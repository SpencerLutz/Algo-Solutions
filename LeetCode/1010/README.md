# [1010 - Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60)

### Difficulty: Medium

## Hints
- <details>
    <summary>Hint 1</summary>
    This is very similar to Two Sum.
  </details>
- <details>
    <summary>Hint 2</summary>
    We only need to consider each value modulo 60.
  </details>
- <details>
    <summary>Hint 3</summary>
    What does it mean mathematically for 2 song lengths <code>a</code> and <code>b</code> to form a pair? Can we find <code>b</code> in terms of <code>a</code> and use this to check for pairs more efficiently?
  </details>

## Solution
This problem is very similar to [Two Sum](https://leetcode.com/problems/two-sum/) ([Solution](../0001/)), the difference being that instead of adding to a target value, our numbers must add to a multiple of 60. We also need to find the number of pairs, rather than simply returning one.

Recall that the $O(n)$ solution to Two Sum involves iterating through the given list, keeping a hash map of values we've already seen and their indices. We then check to see if the current number's complement (`target - n`) exists in the set. If so, we return our pair. Given how similar this problem is to ours, it should be our first instinct to try to adapt the solution to work with our problem. 

We first recognize that we no longer need to keep track of indices, only the number of pairs. Thus, we can use the hash map to map each value in the list to the number of valid pairs that include it:
```python
count = {}

# Incrementing k when we encounter a pair:
if k in count:
    count[k] += 1
else:
    count[k] = 1

# Accessing k to get count:
cnt = count[k] if k in count else 0
```
This works perfectly fine, but we can simplify it a bit. Because we only care about each value modulo 60, we only have 60 possible values. Thus, we can use an array to simplify our accessing and modifying, while still maintaining decent space complexity:
```python
count = [0] * 60

# Incrementing k when we encounter a pair:
count[k] += 1

# Accessing k to get count:
cnt = count[k]
```
Much simpler. Now that we have a fast and efficient way to access our counts, how do we use this?

Like in Two Sum, we need to loop through the values we are given and check for 'complements' in our hash map. Our complement in this case is any number $n$ such that $$(n + s) \mod 60 = 0 $$
$$ \Rightarrow ((n \mod 60) + (s \mod 60)) \mod 60 = 0$$
$$ \Rightarrow n \mod 60 = -s \mod 60 $$
`count[k]` stores how many times we have seen `k` in the list so far. Thus we can see how many times a complement for `s` has been seen with `count[-s % 60]`. Each complement `n` represents a valid pair `(s, n)` such that `s + n % 60 == 0`, so we should add this count to our total.
```python
for s in time:
    total += count[-s % 60]
```
We also need to be updating count, so we add:
```python
    count[s % 60] += 1
```
We must do this after we look for complements; if we did it before, and `s` happened to be its own complement (e.g. 30), we would be including the pair `(s, s)` in our count, which is invalid.

Finally, we simply return our total:
```python
return total
```