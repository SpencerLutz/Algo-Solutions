#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
    int c = 1, l = 1;
    for (int i = 1; i < (int)s.length(); i++) {
        if (s[i] == s[i - 1]) {
            c++;
            if (c > l) l = c;
        } else c = 1;
    }
    cout << l;
}