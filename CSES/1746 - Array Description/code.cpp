#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define pem(x, y, m) (x = (x + y) % m)

int dp[2][101];
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n, m; cin >> n >> m;

    rep (i, 0, n) {
        cin >> w;
        rep (j, 1, m + 1) if (w == 0 || w == j) {
            if (i == 0) dp[i % 2][j] = 1;
            else {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (j != 1) pem(dp[i % 2][j], dp[(i - 1) % 2][j - 1], MOD);
                if (j != m) pem(dp[i % 2][j], dp[(i - 1) % 2][j + 1], MOD);
            }
        } else dp[i % 2][j] = 0;
    }

    int ans = 0;
    rep (i, 1, m + 1) pem(ans, dp[(n - 1) % 2][i], MOD);
    cout << ans;
}
