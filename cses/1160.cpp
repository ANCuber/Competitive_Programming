#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back



signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector<int> g(n+2);
    for (int i = 1; i <= n; ++i) {
        int a; cin>>a;
        g[i] = a;
    }
    while(q--) {
        int x, y; cin>>x>>y;
        
    }
    return 0;
}
