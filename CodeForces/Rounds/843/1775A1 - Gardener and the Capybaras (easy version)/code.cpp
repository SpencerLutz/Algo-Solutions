#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        bool done = false;
        rep (a, 1, n - 1) {
            string s1 = s.substr(0, a);
            rep (b, a + 1, n) { 
                string s2 = s.substr(a, b - a);
                string s3 = s.substr(b, n - b);
                if (s1 <= s2 && s2 >= s3 || s1 >= s2 && s2 <= s3) {
                    cout << s1 << " " << s2 << " " << s3 << "\n";
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        if (!done) cout << ": (\n";
    }
}
