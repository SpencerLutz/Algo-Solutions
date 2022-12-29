#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K; cin >> N >> K;
	const int M = K + 1;
	const int INF = INT_MAX;
	int dp[M], h[M];

	dp[0] = 0;
	cin >> h[0];

	for (int i = 0; i < N; i++) {
		cin >> h[i % M];
		dp[i % M] = INF;
		for (int j = max(0, i - K); j < i; j++) {
            dp[i % M] = min(dp[i % M], dp[j % M] + abs(h[i % M] - h[j % M]));
        }
	}

	cout << dp[(N - 1) % M];
}
