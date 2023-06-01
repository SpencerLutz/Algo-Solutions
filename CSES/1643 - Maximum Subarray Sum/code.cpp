#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define maxs(x, y) (x = max(x, y))
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n;
    ll curr = 0, ans = LLONG_MIN;
    rep (i, 0, n) {
        cin >> w;
        curr += w;
        maxs(ans, curr);
        maxs(curr, (ll)0);
    }
    cout << ans;
}
