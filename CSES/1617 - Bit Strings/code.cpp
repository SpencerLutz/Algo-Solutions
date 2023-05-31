#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r = 1; cin >> n;
    for (int i = 0; i < n; i++) {
        r *= 2; r %= MOD;
    }

    cout << r;
}