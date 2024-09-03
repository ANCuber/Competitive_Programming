#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

/*
XaXX
bcde
XfXX
*/

struct Dice{
    int a = 3, b = 5, c = 1, d = 2, e = 6, f = 4;
    void RotF() {
        int buf = e;
        e = f; f = c; c = a; a = buf;
    }
    void RotR() {
        int buf = e;
        e = d; d = c; c = b; b = buf;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<Dice> d(n+2);
    while(m--) {
        int a, b; cin>>a>>b;
        if (a > 0 && b > 0) swap(d[a],d[b]);
        else if (b == -1) d[a].RotF();
        else d[a].RotR();
    }
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<d[i].c;
    }
    cout<<'\n';
    return 0;
}
