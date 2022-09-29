#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	const int s = k + 1;
	const int mx = INT_MAX;
	int dp[s], h[s];

	for (int i = 0; i < n; i++) {
		int w; cin >> w;
		h[i % s] = w;
		dp[i % s] = i == 0 ? 0 : mx;
		for (int j = max(0, i - k); j < i; j++) {
            dp[i % s] = min(dp[i % s], dp[j % s] + abs(h[j % s]-w));
        }
	}

	cout << dp[(n - 1) % s];
}
