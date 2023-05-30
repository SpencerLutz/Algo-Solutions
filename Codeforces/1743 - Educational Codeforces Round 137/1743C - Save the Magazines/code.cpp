#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;
        int dp[N + 1][2];

        dp[0][0] = 0;
        dp[0][1] = 0;
        rep(i, 1, N + 1) {
            int v; cin >> v;
            if(s[i - 1] == '1') {
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + v);
                dp[i][1] = v + dp[i - 1][1];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0] + v;
            }
        }

        cout << dp[N][0] << "\n";
    }
}