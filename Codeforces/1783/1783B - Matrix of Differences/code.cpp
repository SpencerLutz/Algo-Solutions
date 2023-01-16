#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
		int n; cin >> n;
        int nsq = n*n;
        int o[nsq];
        rep(i, 0, nsq) o[i] = (i & 1 ? nsq - i / 2 : i / 2 + 1);
        rep(i, 0, n) {
            int low = n * i, high = low + n;
            if (i & 1) rrep(j, high - 1, low) cout << o[j] << " ";
            else rep(j, low, high) cout << o[j] << " ";
            cout << "\n";
        }
    }
}
