#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    multiset<int> t;
    int w, c;
    rep (i, 0, n) {
        cin >> w;
        t.insert(w);
    }

    rep(i, 0, m) {
        cin >> c;
        auto x = t.upper_bound(c);
        if (x == t.begin()) cout << "-1\n";
        else {
            cout << *(--x) << "\n";
            t.erase(x);
        }
    }
}
