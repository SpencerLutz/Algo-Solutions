#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n; cin >> n;
    int dp[n];
    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> w;
        int idx = upper_bound(v.begin(), v.end(), w) - v.begin();
        if(idx == (int)v.size()) v.push_back(w);
        else v[idx] = w;
        dp[i] = idx + 1;
    }

    cout << v.size() << "\n";
}
