# [1775 - Equal Sum Arrays With Minimum Number of Operations](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations)

### Difficulty: Medium

## Hints
- <details>
    <summary>Hint 1</summary>
    To approach the same sum, we must increase the sum of the lower-valued list and/or decrease the sum of the higher-valued list.
  </details>
- <details>
    <summary>Hint 2</summary>
    We should only perform at most one operation on any element in <code>nums1</code> or <code>nums2</code>. How can we find the best operation for each element? What makes an operation the 'best'?
  </details>
- <details>
    <summary>Hint 3</summary>
    How does performing each operation affect the difference between the two sums? How do we repeatedly perform the best possible operation until the sums are the same?
  </details>

[//]: # (Include a shorter solution for people experienced with algorithms)

## Solution
### Degenerate/Edge Cases
We can first account for the degenerate cases, where either it is not possible to make the sums equal or the sums are already equal.

To figure out when it is impossible to make the sums equal, we can first examine the example we are given for this case: `nums1 = [1,1,1,1,1,1,1], nums2 = [6]`. As the explanation states, we can't decrease the sum of `nums1` because every value is a `1` (the lowest it can be), and we can't increase the sum of `nums2` because the only value is already a `6` (the highest it can be). And yet, the sum of `nums1` is `7`, and the sum of `nums2` is `6`. 

This gives us the insight that the longer list can only be at most 6 times the length of the shorter list. If this is not the case, even by filling the shorter list with `6`s and the longer list with `1`s, the sum of the shorter list will still be less than the sum of the longer one. We can check for this with:
```python
n1 = len(nums1)
n2 = len(nums2)
if n1 * 6 < n2 or n2 * 6 < n1:
    return -1
```
Figuring out when the sums are already equal is much simpler.
```python
s1 = sum(nums1)
s2 = sum(nums2)
diff = abs(s2 - s1)
if diff == 0:
    return 0
```
### Algorithm
We can restate this problem as trying to get `diff` to equal `0` with as few operations as possible. Thus, we must always be performing the most 'valuable' operation we can, i.e. the operation that reduces `diff` by the most.

Each operation corresponds to changing a value in one of the lists. The only operations that get us closer to the goal are those that increase the sum of the lower-valued list, or decrease the sum of the higher-valued list. We can call these lists `low` and `high` as follows:
```python
if s1 < s2:
    low = nums1
    high = nums2
else:
    low = nums2
    high = nums1
```
Our best operation on each element will always be to change a value in `low` to `6`, or change a value in `high` to `1`. Thus the value of the best operation for each element `l` of `low` will always be `6 - l`, as this is the amount `diff` is decreased by when replacing `l` with `6`. Similarly, the value of the best operation for each element `h` in `high` will always be `h - 1`. Thus we can get a list of the best operations with:
```python
values_low = [6 - l for l in low]
values_high = [h - 1 for h in high]
```
We don't care about *what* operations we take to get `diff` to `0`, only *how many* operations we need. If we take the highest-valued operations first, we will minimize this count. We get the highest-valued operations as follows:
```python
values = values_low + values_high
values.sort(reverse=True)
```
Keep in mind each element `v` of `values` corresponds to an operation that reduces `diff` by **up to** `v`. 

For example, a `2` in `low` would correspond to a `4` in `values` (because changing that `2` to a `6` would decrease `diff` by `4`). However, we could just as easily change that `2` to something less than `6`. `4` is just the *maximum* value we can get from that `2`.

Thus, to get the final operation count, we can iterate through `values` (which is reverse sorted so we will always take the best operation first) and subtract each one from `diff` until `diff <= 0`. (The `<=` is because if we take an operation that brings `diff` below `0`, that means we can also take an operation that brings `diff` to exactly `0`, as each element of `values` is simply the maximum possible.) The code for this is:
```python
total = 0
for v in values:
    diff -= v
    total += 1
    if diff <= 0:
        return total
```
And just in case anything falls through somehow, we finish it off with
```python
return -1
```



