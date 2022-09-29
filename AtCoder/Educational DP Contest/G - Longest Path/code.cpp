#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)

const int mx = 1e5 + 1;
int dp[mx] = {};
bool visited[mx] = {};
int p[mx];
map<int,vector<int> > e;

void dfs(int v) {
	visited[v] = true;
	for (int a : e[v]) {
		dp[a] = max(dp[a], dp[v] + 1);
		if(!--p[a]) dfs(a);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	rep (i, 0, m) {
		int x, y; cin >> x >> y;
		p[y - 1]++;
		e[x - 1].push_back(y - 1);
	}

	rep (i, 0, n) 
		if(!visited[i] && p[i] == 0) dfs(i);
		
	cout << *max_element(dp, dp + n);
}
