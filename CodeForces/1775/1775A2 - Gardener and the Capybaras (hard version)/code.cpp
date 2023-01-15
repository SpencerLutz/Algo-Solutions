#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int i = s[1] == 'a' ? 2 : s.length() - 1;
        cout << s[0] << " " << s.substr(1, i - 1) << " " << s.substr(i) << "\n";
    }
}
