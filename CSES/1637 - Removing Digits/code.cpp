#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define mins(x, y) (x = min(x, y))
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi dp(n + 1, INT_MAX);
    rep (i, 0, min(10, n + 1)) dp[i] = 1;
    rep (i, 1, n + 1) rep (j, 1, 10) 
        if (i + j <= n && to_string(i + j).find('0' + j) != string::npos)
            mins(dp[i + j], dp[i] + 1);
    cout << dp[n];
}
