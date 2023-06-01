#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, x; cin >> n >> x;
    vi a(n);
    int sum = 0, start = 0, ans = 0;
    rep (i, 0, n) {
        cin >> a[i];
        while (sum + a[i] > x && sum >= 0) sum -= a[start++];
        if (sum + a[i] == x) ans++;
        sum += a[i];
    }
    cout << ans;
}