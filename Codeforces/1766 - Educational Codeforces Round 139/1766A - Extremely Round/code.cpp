#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int n; cin >> n;
		int lg = floor(log10(n));
		int ans = n / pow(10, lg) + lg * 9;
        cout << ans << "\n";
    }
}