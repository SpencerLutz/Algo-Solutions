#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int dp[5001][5001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();
    rep(i, 0, n + 1) dp[i][0] = i;
    rep(i, 0, m + 1) dp[0][i] = i;
    rep(i, 1, n + 1) rep(j,1,m+1) 
        dp[i][j] = min({
            dp[i - 1][j] + 1, 
            dp[i][j - 1] + 1, 
            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])
        });
    cout << dp[n][m];
}
