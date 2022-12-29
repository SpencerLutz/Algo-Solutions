#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int dp[2][3];
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	for (int i = 1; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		dp[i % 2][0] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]) + a;
		dp[i % 2][1] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]) + b;
		dp[i % 2][2] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]) + c;
	}

	cout << *max_element(dp[(N - 1) % 2], dp[(N - 1) % 2] + 3);
}
