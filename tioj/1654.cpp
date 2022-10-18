#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > ch(n+1);
    vector<int> dep(n+1,0);
    for (int i = 2; i <= n; ++i) {
        int p; cin>>p;
        ch[p].pb(i);
    }
    
    return 0;
}
