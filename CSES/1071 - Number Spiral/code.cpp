#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t, x, y, a; cin >> t;
    while (t--) {
        cin >> y >> x;
        a = max(x, y);
        cout << a * a - a + 1 + (a % 2 ? x - y : y - x) << "\n";
    }
}