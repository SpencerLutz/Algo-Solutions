#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
#define maxs(x, y) (x = max(x, y))

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    vi d(n);
    rep (i,0,n) cin >> a[i] >> d[i];
    sort(all(a));
    sort(all(d));
    int i = 0, j = 0, total = 0, best = 0;
    while (i < n && j < n) {
        if (a[i] < d[j]) {
            total++; i++;
        } else if (a[i] > d[j]) {
            total--; j++;
        } else {
            i++; j++;
        }
        maxs(best, total);
    }
    cout << best;
}
