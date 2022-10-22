#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[3], h[3];
	int N; cin >> N >> h[0] >> h[1];

	dp[0] = 0; 
	dp[1] = abs(h[0] - h[1]);

	for (int i = 2; i < N; i++) {
		cin >> h[i % 3];
		dp[i % 3] = min(
			dp[(i - 1) % 3] + abs(h[(i - 1) % 3] - h[i % 3]),
			dp[(i - 2) % 3] + abs(h[(i - 2) % 3] - h[i % 3])
		);
	}
    
	cout << dp[(N - 1) % 3];
}
