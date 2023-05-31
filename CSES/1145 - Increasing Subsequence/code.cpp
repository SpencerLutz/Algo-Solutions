#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb(c) push_back(c)
#define mins(x, y) (x = min(x, y))
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n;
    vi v;
    rep (i, 0, n) {
        cin >> w;
        int idx = lower_bound(all(v), w) - v.begin();
        if (idx == sz(v)) v.pb(w);
        else mins(v[idx], w);
    }
    cout << sz(v);
}
