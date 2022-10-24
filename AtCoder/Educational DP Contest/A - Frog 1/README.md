# [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)

## Hints
- <details>
    <summary>Hint 1</summary>
    What definition for our state allows the solution to fall into place at <code>dp[N]</code>?
  </details>
- <details>
    <summary>Hint 2</summary>
    If <code>dp[i]</code> is the minimum cost to <code>i</code>, what is the cost to <code>j</code> through <code>i</code> for <code>j = i + 1</code> or <code>j = i + 2</code>? How does this relate to <code>dp[j]</code>?
  </details>

## DP Setup
### State
Let $dp_i$ be the minimum possible total cost incurred before the frog reaches stone $i$. Thus, our solution (the minimum possible total cost incurred before the frog reaches stone N) is simply $dp_N$.

### Transition
The cost $c_{ij}$ to reach stone $j$ from stone $i$ is $|h_j-h_i|$. The total cost to reach stone $j$ through stone $i$ is $c_{ij}$ + the minimum total cost to reach stone $i$ $(dp_i)$. This becomes $|h_i-h_j| + dp_i$. For all $j \geq 2$, we have a choice between $i = j - 1$ or $i = j - 2$. We want to find the *minimum* possible cost, so we take the minimum of the two options to get

$$dp_j = \min(|h_j-h_{j-1}| + dp_{j-1}, |h_j-h_{j-2}| + dp_{j-2})$$

We start on stone 1, so $dp_1 = 0$. 

For $j = 2$, there is no $j-2$, so we just have $dp_2 = |h_2-h_1| + dp_1 = |h_2-h_1|$.

## Solution ([Code](code.cpp))
*(Note that* `dp[0]` $\equiv dp_1$, `h[0]` $\equiv h_1$.)

We have $N \leq 10^5$, so we can create our `dp` and `h` arrays:
```cpp
int mx = 1e5;
int dp[mx], h[mx];
```
We get `N` and the first two elements of `h` as follows:
```cpp
int N;
cin >> N >> h[0] >> h[1];
```
We need to read in the first 2 `h` values to calculate `dp[1]`:
```cpp
dp[0] = 0; 
dp[1] = abs(h[0] - h[1]);
```
Now that we have `dp[0]`, `dp[1]`, `h[0]`, and `h[1]`, we can loop through the stones and apply our DP relationship. We start with `dp[2]` and iterate until we have calculated `dp[N - 1]`, reading the current height into `h[i]` at each iteration:
```cpp
for (int i = 2; i < N; i++) {
	cin >> h[i];
```
Now we implement our transition:
```cpp
	dp[i] = min(
		dp[i - 1] + abs(h[i - 1] - h[i]),
		dp[i - 2] + abs(h[i - 2] - h[i])
	);
}
```
Finally, we return the solution:
```cpp
cout << dp[N - 1];
```
### Optimization (Optional)
We can optimize the space complexity of this algorithm. Notice that at each iteration, we are only ever accessing `dp` and `h` for `i - 2`, `i - 1`, and `i`. Once we reach iteration `k`, we no longer need any values before `k - 2`. Thus we only really need to keep track of 3 values for each variable, instead of all $N \leq 10^5$.

One way to optimize this would be to just have 6 variables, e.g. `dpa`, `dpb`, `dpc`, `ha`, `hb`, `hc`. At each iteration of our loop, we could update them with 
```cpp
hc = hb;
hb = ha;
cin >> ha;
dpc = dpb;
dpb = dpa;
dpa = min(dpb + abs(hb - ha), dpc + abs(hc - ha));
```
This is a perfectly fine implementation, and it does make the transition step look cleaner. However, suppose the problem required us to look at the 5 previous stones. Already, this method brings us to 12 variables to keep track of, which is pretty bulky and ugly code.

Instead, we can keep `dp` and `h` as arrays, but make the arrays of length 3. Instead of shifting values down the arrays (`h[0] = h[1]; h[1] = h[2]; ...`) as we iterate, we can use each index modulo 3, like so:
```cpp
cin >> h[i % 3];
dp[i % 3] = min(
	dp[(i - 1) % 3] + abs(h[(i - 1) % 3] - h[i % 3]),
	dp[(i - 2) % 3] + abs(h[(i - 2) % 3] - h[i % 3])
);
```
I like to think of this method as laying repeating windows of length 3 along the original $10^5$-long array. At any one iteration, we only ever need to access data in the currrent window $(w_c)$ and the window behind it $(w_p)$, and we will never have to access both $w_c[i]$ and $w_p[i]$, as $w_p[i]$ is more than 2 indices behind $w_c[i]$. Thus we can take the end of $w_p$ (the data we need to access) and stick it to the end of $w_c$ (in place of the data we have not reached). Now the value 2 indices behind $i$ is just $i + 1$, or $(i - 2) \mod 3$. 

(I wish I could visualize this. If this doesn't make sense, sorry :/)

The code I posted uses this optimization, and ends up using ~20% less memory than the unoptimized version. On this problem, where our arrays are only $10^5$ elements, the optimization is pretty small. However, on bigger problems with arrays that are too big to fully store, using this method can turn an impossible problem into an easy one, reducing memory usage by many orders of magnitude.
