#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

vector<string> rna;
vector<vector<int> > g, dp;
map<char,int> mp;

void dfs(int u, int p) {
    for (auto v : g[u]) dfs(v,p);
    for (int i = 1; i <= 4; ++i) {//u as what?
        if (rna[u][p] == '@' || i == mp[rna[u][p]]) {
            dp[u][i] = 0;
            for (auto v : g[u]) {
                int mn = 1e9;
                for (int j = 1; j <= 4; ++j) {
                    if (j == i) mn = min(mn,dp[v][j]);
                    else mn = min(mn,dp[v][j]+1);
                }
                dp[u][i] += mn;
            }
        } else {
            dp[u][i] = 2e9;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, rt; cin>>n>>m;    
    mp['A'] = 1, mp['U'] = 2, mp['C'] = 3, mp['G'] = 4;
    rna.resize(n+2);
    g.resize(n+2);
    dp.assign(n+2,vector<int> (5,2e9));
    for (int i = 0; i < n; ++i) {
        int a, b; string s;
        cin>>a>>b>>s;
        if (a == b) rt = a;
        else g[b].push_back(a);
        rna[a] = s;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        dfs(rt,i);
        ans += min({dp[rt][1],dp[rt][2],dp[rt][3],dp[rt][4]});
    }
    cout<<ans<<'\n';
    return 0;
}
