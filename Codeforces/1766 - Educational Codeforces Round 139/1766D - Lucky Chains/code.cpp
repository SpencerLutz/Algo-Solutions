#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define mins(x, y) (x = min(x, y))

const int mx = 1e7 + 1;
int f[mx];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    rep (i, 0, mx) f[i] = i;
    rep (i, 2, mx) if (f[i] == i)
        for (int d = i * 2; d < mx; d += i) f[d] = i;

	int t; cin >> t;
    while (t--) {
		int x, y; cin >> x >> y;
        int d = y - x;
        if (d == 1) {
            cout << "-1\n";
            continue;
        }

        int ans = INT_MAX;
        while (d > 1) {
            if (x % f[d] == 0) {
                ans = 0;
                break;
            } else {
                mins(ans, f[d] - x % f[d]);
            }
            d /= f[d];
        }

        cout << ans << "\n";
    }
}