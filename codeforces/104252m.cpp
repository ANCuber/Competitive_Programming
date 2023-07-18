#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dl[4] = {1,-1,0,0};
int dp[4] = {0,0,1,-1};
int n, m;

int dfs(int ly, int p, vector<int> &ring, vector<vector<int> > &mz, vector<vector<int> > &vis) {
    vis[ly][p] = 1;
    if (ly == n+1) return 1;
    
    int tmp = 0;
    
    for (int i = 0; i < 4; ++i) { 
        if (i == 1 && !ly) continue;
        int cur = (p+dp[i]+m)%m;
        if (vis[ly+dl[i]][cur]) continue;
        
        int flg = 0;
        for (int j = 0; j < m; ++j) {
            if (!ring[j]) continue;
            if (mz[ly+dl[i]][(cur+j)%m]) flg = 1;
        }
        
        if (!flg) tmp = max(tmp,dfs(ly+dl[i],cur,ring,mz,vis));
    }
    
    return tmp;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<int> a(m+5,0), b(m+5,0);
    vector<vector<int> > g(n+5,vector<int>(m+5,0)), vis(n+5,vector<int>(m+5,0));
    vector<vector<int> > vis1(n+5,vector<int>(m+5,0));
    string x; cin>>x;
    for (int i = 0; i < m; ++i) {
        b[m-i-1] = a[i] = x[i]-'0';
    }
    for (int i = 1; i <= n; ++i) { 
        cin>>x;
        for (int j = 0; j < m; ++j) {
            g[i][j] = x[j]-'0';
        }
    }
    if (dfs(0,0,a,g,vis) || dfs(0,0,b,g,vis1)) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    
    return 0;
}
