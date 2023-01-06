#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
typedef vector<int> vi;

const int mx = 301;
double dp[mx][mx][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N; cin >> N;
    vi h(3);
    rep (i, 0, N) {
        int w; cin >> w;
        h[w - 1]++;
    }

    dp[0][0][0] = 0;

    rep (c, 0, N + 1) rep (b, 0, N + 1) rep (a, 0, N + 1) {
        double s = a + b + c;
        if(s > N || s == 0) continue;
        dp[a][b][c % 2] = 1 + (N / s - 1);
        if (a > 0) dp[a][b][c % 2] += (a / s) * dp[a - 1][b][c % 2];
        if (b > 0) dp[a][b][c % 2] += (b / s) * dp[a + 1][b - 1][c % 2];
        if (c > 0) dp[a][b][c % 2] += (c / s) * dp[a][b + 1][(c - 1) % 2];
    }

    cout << fixed << setprecision(20) << dp[h[0]][h[1]][h[2] % 2];
}