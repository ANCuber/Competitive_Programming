#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int n, m, s, t;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>s>>t;    
    vector<int> c(n+1,0);
    vector<vector<int> > g(n+1);
    for (int i = 1; i <= n; ++i) cin>>c[i];
    int u,v;
    while(m--) {
        cin>>u>>v;
        g[v].push_back(u);
    }
    vector<int> dp(n+1,-1e9);
    dp[s] = 0;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            
        }
    }

    return 0;
}
