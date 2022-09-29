#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int mod = 1e9 + 7;
	int H, W; cin >> H >> W;
	int dp[2][W + 1];
	rep (i, 0, W+1) dp[0][i] = 0;
	dp[1][0] = 0;

	rep (i, 1, H + 1) {
		rep (j, 1, W + 1) {
			char x; cin >> x;
			if(i == 1 && j == 1) dp[i][j] = 1;
			else if(x == '#') dp[i % 2][j] = 0;
			else dp[i % 2][j] = (dp[(i - 1) % 2][j] + dp[i % 2][j - 1]) % mod;
		}
	}
	
	cout << dp[H % 2][W];
}
