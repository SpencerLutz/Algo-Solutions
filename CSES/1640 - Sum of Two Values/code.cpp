#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> vs;
    int n, x, w; cin >> n >> x;
    rep (i, 0, n) {
        cin >> w;
        if (x < w) continue;
        if (vs.find(w) != vs.end()) {
            cout << (vs[w] + 1) << " " << (i + 1);
            return 0;
        }
        vs[x - w] = i;
    }
    cout << "IMPOSSIBLE";

}
