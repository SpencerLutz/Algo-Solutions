#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, pl, w, t = 0; cin >> n >> pl;
    while (--n) {
        cin >> w;
        if (w >= pl) pl = w;
        else t += pl - w;
    }
    cout << t;
}