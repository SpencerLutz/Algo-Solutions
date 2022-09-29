#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mx = 1e5+1;

	int dp[mx], h[mx];
	int n, f, k; cin >> n >> f >> k;

	dp[0] = 0; 
    h[0] = f;
	dp[1] = abs(f-k); 
    h[1] = k;

	for (int i = 2; i < n; i++) {
		int w; cin >> w;
		h[i] = w;
		dp[i] = min(dp[i-1]+abs(h[i-1]-w), dp[i-2]+abs(h[i-2]-w));
	}
    
	cout << dp[n-1];
}
