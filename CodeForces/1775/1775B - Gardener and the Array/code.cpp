#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb(c) push_back(c)
typedef vector<int> vi;

const int mx = 2e5+1;
int h[mx];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        if (N == 1) {
            int k; cin >> k;
            int w; rep (j, 0, k) cin >> w;
            cout << "No\n";
            continue;
        }

        vi v[N];
        rep (i, 0, mx) h[i] = 0;
        rep (i, 0, N) {
            int k; cin >> k;
            rep (j, 0, k) {
                int w; cin >> w;
                v[i].pb(w);
                h[w]++;
            }
        }
        
        bool f = false;
        rep (i, 0, N) {
            bool g = true;
            trav(a, v[i]) {
                if (h[a] < 2) {
                    g = false;
                    break;
                }
            }
            if (g) {
                f = true;
                break;
            }
        }

        cout << (f ? "Yes" : "No") << "\n";
    }
}