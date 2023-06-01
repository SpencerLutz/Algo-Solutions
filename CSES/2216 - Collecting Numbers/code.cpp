#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef unordered_set<int> usi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, ans = 0; cin >> n;
    usi seen;
    rep (i, 0, n) {
        cin >> w;
        if (w == 1) ans++;
        else if (seen.find(w - 1) == seen.end()) ans++;
        seen.insert(w);
    }
    cout << ans;
}
