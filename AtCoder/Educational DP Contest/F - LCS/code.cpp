#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int ls = s.length(), lt = t.length();
	string dp[2][lt + 1];

	rep (i, 0, ls + 1) dp[i % 2][0] = "";
	rep (j, 0, lt + 1) dp[0][j] = "";

	rep (i, 1, ls + 1) {
		rep (j, 1, lt + 1) {
			if(s[i - 1] == t[j - 1]) 
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + s[i - 1];
			else dp[i % 2][j] = 
				dp[(i - 1) % 2][j].length() > dp[i % 2][j - 1].length() ? 
					dp[(i - 1) % 2][j] : 
					dp[i % 2][j - 1];
		}
	}

	cout << dp[ls % 2][lt];
}