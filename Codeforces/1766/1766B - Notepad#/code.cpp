#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define mp(x, y) make_pair((x), (y))

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int n; cin >> n;
        string s; cin >> s;
        unordered_map<string, int> cs;

        bool yes = false;
        rep (i, 0, n - 1) {
            string th = s.substr(i, 2);
            if (cs.find(th) == cs.end()) 
                cs.insert(mp(th, i));
            else if (cs.at(th) < i - 1) {
                yes = true;
                break;
            }
        }

        cout << (yes ? "YES" : "NO") << "\n";
    }
}