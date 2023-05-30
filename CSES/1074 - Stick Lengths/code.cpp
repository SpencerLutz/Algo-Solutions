#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep (i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    int med = a[n / 2];
    long long sol = 0;
    rep (i, 0, n) sol += abs(a[i] - med);
    cout << sol;
}
