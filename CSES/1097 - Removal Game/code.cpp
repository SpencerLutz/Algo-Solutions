#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll a[n], dp[n][n], p[n];
    rep(i, 0, n) {
        cin >> a[i];
        dp[i][i] = a[i];
        p[i] = (i == 0 ? 0 : p[i - 1]) + a[i];
    }
    rrep(l, n - 2, 0) rep(r, l + 1, n)
        dp[l][r] = p[r] - (l == 0 ? 0 : p[l - 1])
            - min(dp[l + 1][r], dp[l][r - 1]);

    cout << dp[0][n - 1];
}
