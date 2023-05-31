#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vi p(n);
    rep (i, 0, n) cin >> p[i];
    sort(all(p));
    int ans = 0, i = 0, j = n - 1;
    while (i <= j) {
        if (i != j && p[i] + p[j] <= x) {
            ans++; i++; j--;
        } else if (p[j] <= x) {
            ans++; j--;
        }
    }

    cout << ans;
}
