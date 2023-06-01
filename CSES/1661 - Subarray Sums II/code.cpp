#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, w; cin >> n >> x;
    unordered_map<ll, int> sums{{0, 1}};
    ll p = 0, ans = 0;
    rep (i, 0, n) {
        cin >> w;
        p += w;
        ans += sums[p - x];
        sums[p]++;
    }
    cout << ans;
}
