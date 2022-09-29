#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= (b); --i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, W; cin >> N >> W;
	long long dp[W + 1];
	rep (i, 0, W + 1) dp[i] = 0;

	rep (i, 0, N) {
		long long w, v; cin >> w >> v;
		rrep (j, W - w, 0) {
			dp[j + w] = max(dp[j + w], dp[j] + v);
		}
	}

	cout << dp[W];
}
