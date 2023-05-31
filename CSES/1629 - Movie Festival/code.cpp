#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> t(n);
    rep (i,0,n) cin >> t[i].second >> t[i].first;
    sort(all(t));
    int ce = 0, ans = 0;
    trav (p, t) if (p.second >= ce) {
        ans++;
        ce = p.first;
    }
    cout << ans;
}
