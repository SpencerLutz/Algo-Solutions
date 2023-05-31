#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    rep (i, 2, n + 1) rep (j, 1, 7) if (i - j >= 0) 
        dp[i] = (dp[i] + dp[i - j]) % MOD;
    cout << dp[n];
}
