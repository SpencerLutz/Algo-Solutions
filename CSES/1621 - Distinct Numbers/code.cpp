#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, w; cin >> n;
    set<int> s;
    while (n--) {
        cin >> w; 
        s.insert(w);
    }
    cout << s.size() << "\n";
}
