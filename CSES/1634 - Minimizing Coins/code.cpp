#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n, x; cin >> n >> x;

    vi dp(x + 1, -1);
    dp[0] = 0;
    rep (i, 0, n) {
        cin >> w;
        rep (j, 0, x + 1) if (j + w <= x && dp[j] != -1)
            dp[j + w] = (dp[j + w] == -1 ? dp[j] + 1 : min(dp[j + w], dp[j] + 1));
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}
