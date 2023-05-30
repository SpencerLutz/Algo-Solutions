#include <bits/stdc++.h>
using namespace std;

#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        ll ans = n;
        ll minm = LLONG_MAX;
        for (ll i = 1; i > 0; i <<= 1) {
            if (!(n & i) && (x & i)) {
                minm = -1;
                break;
            } else if (!(n & i)) continue;
            ll w = i << 1;
            ll f = n + w - (n & (w - 1));
            if (x & i) mins(minm, f);
            else maxs(ans, f);
        }
        if (ans < minm) cout << ans << "\n";
        else cout << "-1\n";
    }
}
