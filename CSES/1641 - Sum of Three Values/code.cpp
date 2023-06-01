#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef vector<int> vi;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vi a(n);
    rep (i, 0, n) cin >> a[i];
    unordered_map<int, int, custom_hash> mp;
    rep (i, 0, n) if (a[i] <= x) mp[x - a[i]] = i;
    rep (i, 0, n - 1) rep (j, i + 1, n)  
        if (mp.find(a[i] + a[j]) != mp.end() && mp[a[i] + a[j]] != i && mp[a[i] + a[j]] != j) {
        cout << (i + 1) << " " << (j + 1) << " " << (mp[a[i] + a[j]] + 1);
        return 0;
    }
    cout << "IMPOSSIBLE";
}
