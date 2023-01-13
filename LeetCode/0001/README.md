# [1 - Two Sum](https://leetcode.com/problems/two-sum)

### Difficulty: Easy

## Hints
- <details>
    <summary>Hint 1</summary>
    Instead of thinking about the problem as searching every possible pair for one that works, we can think about it as figuring out if a valid pair exists for any element <code>n</code> of <code>nums</code>.
  </details>
- <details>
    <summary>Hint 2</summary>
    What data structure allows us to both check if a value is in <code>nums</code> and retrieve its index in <code>O(1)</code> time?
  </details>
- <details>
    <summary>Hint 3</summary>
    How can we store data in this data structure and check for pairs in a single loop?
  </details>

## Solution
The naive solution to this problem would be to generate every possible pair with nested for loops, sum each pair, and return the one that equals `target`. This is theoretically very simple, but because we are manually checking every combination, of which there are $\frac{n(n-1)}{2}$ (if we properly avoid double counting), the resulting algorithm would be $O(n^2)$. We can do better.

Instead of thinking about the problem as searching every pair for one that works, we can think about it as figuring out if a valid pair exists for any element `n` of `nums`. If we can determine whether or not a pair containing `n` exists in $O(1)$ time, checking this for every element of `nums` will yield an $O(n)$ algorithm, much faster than our naive approach.

So given `n`, how can we check if a valid pair containing `n` exists? We can restate this question as finding a pair `(n, m)` such that `m` is in `nums` and `n + m == target`. Wait! This means `m = target - n`! So we already know what our pair is: `(n, target - n)`. We can find this second value (known as the 'complement' of `n`) in $O(1)$ time - it's just subtraction.

The only thing left to do is figure out if `target - n` is in `nums`, and if so, find its index. We could just do: 
```python
try: 
    j = nums.index(target - n)
    return (i, j)
except:
    continue
```
But `index()` runs in $O(n)$ time (it has to search up to the entire array), which is too slow. To do this in $O(1)$ time, we need to use a data structure that allows this, like a [hash map](https://en.wikipedia.org/wiki/Hash_table). If we map each value to its index in `nums`, we can check if `target - n` is in the hash map and get its index in $O(1)$ time. We can create our hash map with:
```python
hash_map = {}
```
So our approach now might be to loop through `nums` and fill in the hash map with indices, then loop through `nums` again to check each `n` and see if `target - n` is in our hash map. This is a great $O(n)$ solution, but we can make it even faster by only using one loop:
```python
for i, n in enumerate(nums):
    if target - n in hash_map:
        return [i, hash_map[target - n]]
    else:
        hash_map[n] = i
```
Unless we have a solution with our current element, we simply add the index of the current value to `hash_map`. If we do have a solution, i.e. if `target - n` has already been seen in our loop and added to `hash_map`, we return it.

But what if `target - n` is in `nums`, but we just haven't seen it yet? (i.e. `target - n` comes after `n` in `nums`.) Will our algorithm still find the pair? Yes! Even if we don't see the pair on `n`'s iteration, by the time we get to `target - n`, `n` will be in `hash_map`, and because `(target - n) + n = target`, the pair will be found and returned.

That's it!
