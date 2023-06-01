#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define rrep(i, a, b) for(int i = (a); i >= (b); --i)
#define trav(a, x) for(auto& a : x)

int h[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, r = ""; cin >> s;
    int ol = -1;
    trav (c, s) h[c - 'A']++;

    bool even = !(s.length() % 2);
    rep (i, 0, 26) if (h[i] % 2) {
        if (even) {
            cout << "NO SOLUTION";
            return 0;
        } else {
            even = true;
            ol = i;
        }
    }

    rep (i, 0, 26) if (i != ol) 
        rep (j, 0, h[i] / 2) r += i + 'A';
    if (s.length() % 2)
        rep (i, 0, h[ol]) r += ol + 'A';
    rrep (i, 25, 0) if (i != ol)
        rep (j, 0, h[i] / 2) r += i + 'A';

    cout << r;
}