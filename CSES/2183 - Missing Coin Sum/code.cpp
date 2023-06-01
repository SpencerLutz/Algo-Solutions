#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n);
    rep (i, 0, n) cin >> a[i];
    sort(all(a));
    
    ll sum = 0;
    rep (i, 0, n) {
        if (a[i] - sum > 1) {
            cout << (sum + 1);
            return 0;
        } else sum += a[i];
    }
    cout << (sum + 1);
}
