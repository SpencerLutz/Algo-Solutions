#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= (b); --i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int mx = 1e5;
	long long mv = 1e18;

	int N, W; cin >> N >> W;
	long long dp[mx + 1];
	dp[0] = 0;
	rep (i, 1, mx + 1) dp[i] = mv;

	rep (i, 0, N) {
		int w, v; cin >> w >> v;
		rrep(j, mx - v, 0) {
			dp[j + v] = min(dp[j + v], dp[j] + w);
		}
	}
	rrep (i, mx, 0) {
		if (dp[i] <= W) {
			cout << i;
			return 0;
		}
	}
}
