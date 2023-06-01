#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define pem(x, y, m) (x = (x + y) % m)
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n, x; cin >> n >> x;
    vi c(n);
    rep (i, 0, n) cin >> c[i];
    vi dp(x + 1);
    dp[0] = 1;
    rep (i, 1, x + 1) trav (j, c) if (i - j >= 0) 
        pem(dp[i], dp[i - j], MOD);
    cout << dp[x];
}
