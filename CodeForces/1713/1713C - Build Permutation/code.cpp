#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+1;
int sol[mx];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        int s, l, n, r = N - 1;
        while (r >= 0) {
            s = sqrt(2 * r);
            l = s * s - r;
            n = l - 1;
            while (l <= r) {
                sol[l] = r;
                sol[r--] = l++;
            }
            r = n;
        }
        for (int i = 0; i < N; i++) cout << sol[i] << " ";
        cout << "\n";
    }
}