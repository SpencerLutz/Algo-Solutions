#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if ((a + b) % 3 == 0 && a >= b / 2 && b >= a / 2) cout << "YES\n";
        else cout << "NO\n";
    }
}