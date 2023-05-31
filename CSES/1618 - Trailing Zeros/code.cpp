#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r = 0; cin >> n;
    for (int i = 5; i <= n; i *= 5) r += n / i;
    cout << r;
}