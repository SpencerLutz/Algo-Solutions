#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	double dp[N + 1][N + 1];
	rep (i, 1, N + 1) dp[0][i] = 0;
	dp[0][0] = 1;

	rep (i, 1, N + 1) {
		double p; cin >> p;
		dp[i][0] = dp[i - 1][0] * (1 - p);
		rep (j, 1, N + 1) dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
	}

	cout << fixed << setprecision(12) 
	<< accumulate(dp[N] + N / 2 + 1, dp[N] + N + 1, 0.0);
}
