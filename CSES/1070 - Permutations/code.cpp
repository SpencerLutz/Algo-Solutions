#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if (n == 2 || n == 3) cout << "NO SOLUTION";
    else {
        rep (i, 0, n / 2) cout << 2 * (i + 1) << " ";
        rep (i, 0, (n + 1) / 2) cout << 2 * i + 1 << " ";
    }
}