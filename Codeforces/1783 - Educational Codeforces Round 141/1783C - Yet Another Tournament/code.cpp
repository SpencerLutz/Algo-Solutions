#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

const int mx = 5 * 1e5 + 1;
int w[mx];
int s[mx];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int n, m; cin >> n >> m;
        int total = 0;
        rep (i, 0, n) {
            cin >> w[i];
            total += w[i];
        }
        if (total <= m) {
            cout << "1\n";
            continue;
        }

        partial_sort_copy(w, w + n, s, s + n);
        rep (i, 0, n) s[i] += (i > 0 ? s[i - 1] : 0);
        
        int ans = n + 1;
        int min_w;
        rrep (i, n - 1, 1) {
            min_w = w[i] <= s[i - 1] - s[i - 2] ?
                s[i - 1] : (i > 1 ? s[i - 2] : 0) + w[i];
            if (min_w <= m) {
                ans = n - i;
                break;
            } else if (s[i - 1] <= m) {
                ans = n - i + 1;
                break;
            }
        }
        
        cout << ans << "\n";
    }
}
