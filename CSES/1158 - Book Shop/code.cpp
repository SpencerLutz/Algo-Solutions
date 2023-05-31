#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define maxs(x, y) (x = max(x, y))
typedef vector<int> vi;

int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, v; cin >> n >> x;
    vi p(n + 1);
    rep (i, 1, n + 1) cin >> p[i];
    rep (i, 1, n + 1) {
        cin >> v;
        rrep(j, x, 0) if (j >= p[i]) 
            maxs(dp[j], dp[j - p[i]] + v);
    }
    cout << dp[x] << "\n";
}
