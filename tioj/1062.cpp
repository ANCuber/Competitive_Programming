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
    int m, n; cin>>m>>n;    
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>g[i][j];
        }
    }
    
    
    
    return 0;
}
