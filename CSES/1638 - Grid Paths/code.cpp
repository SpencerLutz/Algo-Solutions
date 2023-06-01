#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define pem(x, y, m) (x = (x + y) % m)

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    char w;
    int dp[n][n];
    dp[0][0] = 1;
    rep (i, 0, n) rep (j, 0, n) {
        cin >> w;
        if (i == 0 && j == 0) {
            if (w == '*') {
                cout << 0;
                return 0;
            }
            continue;
        }
        if (w == '.') {
            dp[i][j] = 0;
            if (i > 0) pem(dp[i][j], dp[i - 1][j], MOD);
            if (j > 0) pem(dp[i][j], dp[i][j - 1], MOD);
        }
        else dp[i][j] = 0;
    }
    cout << dp[n - 1][n - 1];
}
