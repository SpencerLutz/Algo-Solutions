#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

bool w[2][200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int m; cin >> m;
        char h;
        rep (k, 0, 2) rep (i, 0, m) {
            cin >> h;
            w[k][i] = (h == 'B');
        }

        if (m == 1) {
            cout << "YES\n";
            continue;
        }

        bool yes = true;
        bool r = false;
        int s = -1;
        rep (i, 0, m) {
            if (r && s != 0 && !(w[0][i] && w[1][i])) {
                if ((i - s) % 2 && w[0][s-1] == w[0][i] 
                        || !(i - s) % 2 && w[0][s-1] != w[0][i]) {
                    yes = false;
                    break;
                }
                r = false;
                s = -1;
            }
            else {
                if (w[0][i] && w[1][i]) {
                    r = true;
                    s = i;
                } else if (i != 0 && w[0][i] != w[0][i-1]) {
                    yes = false;
                    break;
                }
            }
        }
        
        cout << (yes ? "YES" : "NO") << "\n";
    }
}