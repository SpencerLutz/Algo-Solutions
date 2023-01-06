#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= (b); --i)
typedef vector<int> vi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N; cin >> N;
    ll dp[2][N + 1];
    vi a(N);

    rep (i, 0, N) cin >> a[i];
    rrep (i, N, 0) rrep (j, N, 0) {
        if(i + j > N) continue;
        if(i + j == N) dp[i % 2][j] = 0;
        else dp[i % 2][j] = 
            max(a[i] - dp[(i + 1) % 2][j], a[N - j - 1] - dp[i % 2][j + 1]);
    }

    cout << dp[0][0];
}
