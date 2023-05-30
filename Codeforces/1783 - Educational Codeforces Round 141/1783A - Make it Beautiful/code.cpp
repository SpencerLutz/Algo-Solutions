#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int n; cin >> n;
        int w[n];
        rep (i, 0, n) cin >> w[i];
        sort(w, w + n);
        
        if (w[0] == w[n - 1]) cout << "NO\n";
        else {
            cout << "YES\n" << w[n - 1] << " ";
            rep (i, 0, n - 1) cout << w[i] << " ";
            cout << "\n";
        }
    }
}
