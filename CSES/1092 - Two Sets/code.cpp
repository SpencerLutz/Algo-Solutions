#include <bits/stdc++.h>
using namespace std;

#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb(c) push_back(c)
typedef vector<int> vi;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll total = n * (n + 1) / 2;
    if (total % 2) {
        cout << "NO";
        return 0;
    }

    total /= 2;
    int i = n;
    vi s1;
    while (total > 0) {
        if (total < i) {
            s1.pb(total);
            break;
        } else {
            s1.pb(i);
            total -= i--;
        }
    }

    cout << "YES\n" << sz(s1) << "\n";
    trav(a, s1) cout << a << " ";
    cout << "\n" << (total ? i - 1 : i) << "\n";
    rrep(j, i, 1) if (j != total) cout << j << " ";
}
