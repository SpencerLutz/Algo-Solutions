#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n, w; cin >> x >> n;
    set<int> l{0, x};
    multiset<int> d{x};
    rep (i, 0, n) {
        cin >> w;
        auto next = l.upper_bound(w);
        int ndst = *next - w, pdst = w - *(--next);
        d.erase(d.find(ndst + pdst));
        d.insert(ndst);
        d.insert(pdst);
        l.insert(w);
        cout << *(--d.end()) << " ";
    }
}
