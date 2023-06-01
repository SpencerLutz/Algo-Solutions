#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define mins(x, y) (x = min(x, y))

int dp[500][500];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    rep (i, 1, a + 1) rep (j, 1, b + 1) {
        if (i != j) {
            dp[i][j] = INT_MAX;
            rep (k, 1, i) mins(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            rep (k, 1, j) mins(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }
    cout << dp[a][b];
}
