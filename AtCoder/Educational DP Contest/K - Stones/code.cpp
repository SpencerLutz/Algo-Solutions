#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N, K; cin >> N >> K;
    vi a(N);
    rep (i, 0, N) cin >> a[i];
    bool dp[K + 1];

    rep (i, 0, a[0]) dp[i] = false;
    rep (i, a[0], K + 1) {
        dp[i] = true;
        rep (j, 0, N) if (a[j] <= i) dp[i] &= dp[i - a[j]];
        dp[i] = !dp[i];
    }
    cout << (dp[K] ? "First" : "Second");
}
