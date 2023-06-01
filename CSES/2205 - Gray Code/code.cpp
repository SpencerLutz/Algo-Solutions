#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int m = pow(2, n);
    rep (i, 0, m) {
        int ans = i ^ (i >> 1);
        rep (j, 0, n) {
            cout << (ans & 1);
            ans >>= 1;
        }
        cout << "\n";
    }
}
