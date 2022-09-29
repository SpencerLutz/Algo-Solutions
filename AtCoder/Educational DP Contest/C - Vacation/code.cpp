#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int dp[n][3];
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < n; i++) {
		int h0,h1,h2; cin >> h0 >> h1 >> h2;
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + h0;
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + h1;
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + h2;
	}

	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}
