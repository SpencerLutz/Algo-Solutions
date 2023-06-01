#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto& a : x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w; cin >> n;
    set<int> vals;
    rep (i, 0, n) {
        cin >> w;
        set<int> newv;
        trav (a, vals) newv.insert(a+w);
        vals.merge(newv);
        vals.insert(w);
    }
    cout << vals.size() << "\n";
    trav (a, vals) cout << a << " ";
}
