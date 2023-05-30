# [162 - Find Peak Element](https://leetcode.com/problems/find-peak-element/)

### Difficulty: Medium

## Hints
- <details>
    <summary>Hint 1</summary>
    If a search problem requires a time complexity of <code>O(log n)</code>, this typically means we need some form of binary search.
  </details>
- <details>
    <summary>Hint 2</summary>
    Does the 'slope' at an element of the list (whether the surrounding elements are increasing or decreasing) tell us anything about which side of the element has a peak?
  </details>
- <details>
    <summary>Hint 3</summary>
    Keep in mind that no two neighboring values can be the same, that <code>nums[-1] = nums[n] = -∞</code>, and that the problem asks for <strong>any</strong> of the peaks.
  </details>

## Solution
The naive approach would be to simply iterate through the list, comparing each element with the ones before and after it to determine if it is a peak. However, this would take $O(n)$ time. The problem asks if we can do it in $O(\log(n))$ time, meaning we cannot examine and process every element of the list.

A requirement of $O(\log(n))$ in a search problem often means our solution should implement some form of binary search (specifically, it should repeatedly divide the search space by some factor until a solution is found).

Now, we must figure out how to adapt binary search to this problem. Binary search will examine the middle element of the list, determine whether the solution is on the left or right of that element, and then recursively search the chosen side of the list. We can find the midpoint as follows:
```python
n = len(nums)
...
mp = n//2
```
The question remains: how do we know whether a peak is on the left or right side of this midpoint? 

We know that either `mp` is a peak (e.g. `[1, 2, 1]`), or it is on the way up to a peak (i.e. there is a contiguous strictly increasing or decreasing subsequence containing `mp`, e.g. `[1, 2, 3]`). Keep in mind no two neighboring elements are the same. 

If `nums[mp] < nums[mp + 1]`, we know values are increasing as we move right of `mp`. They must eventually reach a peak, either when the values start decreasing, or when we reach the end of the list (`nums[n] = -∞`). Thus, there must be a peak on the right side. A similar argument holds for the left side.

Thus, if `nums[mp] < nums[mp - 1]`, there is a peak on the left, and if `nums[mp] < nums[mp + 1]`, there is a peak on the right. If neither are true, we know `mp` is a peak. We can thus return here or narrow down the search to half of the search space. We run `findPeakElement` on the chosen half of the list as follows:
```python
if nums[mp] < nums[mp - 1]:
    return self.findPeakElement(nums[: mp])
elif nums[mp] < nums[mp + 1]:
    return self.findPeakElement(nums[mp + 1 :]) + mp + 1
else:
    return mp
```
In the second case, we add `mp + 1` because that call to `findPeakElement` will return the index relative to the start of the right half of the list, which is `mp + 1`. 

Now we need to handle the base cases. Our recursive step will break down if `nums[mp - 1]` or `nums[mp + 1]` don't exist, i.e. if `n < 3`. Our base case for `n = 1` is that the single point must be a peak, so we return `0`.
```python
if n == 1:
    return 0
```
Our base case for `n = 2` is that the greater of the two is a peak, so we return that index.
```python
if n == 2:
    return 0 if nums[0] > nums[1] else 1
```
Now our algorithm will properly recurse, narrowing down the search space until it has focused in on one or two values that must contain a peak. From there, finding the peak is trivial.