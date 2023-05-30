#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, w, t; cin >> n;
    t = (n + 1) * n / 2;
    while (--n) {
        cin >> w;
        t -= w;
    }
    cout << t;
}