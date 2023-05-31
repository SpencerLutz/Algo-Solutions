#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> p(n), a(m);
    rep (i, 0, n) cin >> p[i];
    rep (i, 0, m) cin >> a[i];
    sort(p.begin(), p.end());
    sort(a.begin(), a.end());

    int i = 0, j = 0, ans = 0;
    while (i < m && j < n) {
        if (a[i] >= p[j] - k && a[i] <= p[j] + k) {
            ans++; j++; i++;
        } else if (a[i] > p[j] + k) j++; 
        else i++;
    }

    cout << ans;
}
