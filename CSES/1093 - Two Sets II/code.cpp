#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int dp[500][65000];
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int total = n * (n + 1) / 2;
    if (total % 2) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    rep (i, 1, n)
        rep (j, 0, total / 2 + 1)
            dp[i][j] = (dp[i - 1][j] + (j < i ? 0 : dp[i - 1][j - i])) % MOD;

    cout << dp[n - 1][total / 2];
}
