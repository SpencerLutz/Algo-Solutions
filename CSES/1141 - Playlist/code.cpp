#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define maxs(x, y) (x = max(x, y))

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

    int n, w; cin >> n;
    unordered_map<int, int, custom_hash> seen;
    int start = 0, best = 0;
    rep (i, 0, n) {
        cin >> w;
        if (seen.find(w) != seen.end() && seen[w] >= start) {
            maxs(best, i - start);
            start = seen[w] + 1;
        }
        seen[w] = i;
    }
    cout << max(best, n - start);
}
