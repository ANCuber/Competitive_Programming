#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char x; cin>>x;
            if (x == '.') g[i][j] = 1;
            g[i][j] += g[i-1][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        stack<int> stk;
        for (int j = 1; j <= n; ++j) {
            
        }
        for (int j = n; j > 0; --j) {
            
        }
    }
    
    return 0;
}
