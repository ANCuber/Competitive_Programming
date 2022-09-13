#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

ll m;
int v, e, a, b, s, t;
vector<ll> dp;
vector<bool> vis;

ll solve(vector<vector<int> > &g, int cur) {
    if (vis[cur]) {
        return dp[cur];
    }
    ll ans = 0;
    for (auto i : g[cur]) {
        ans += solve(g,i);
        ans %= m;
    }
    vis[cur] = 1;
    return dp[cur] = ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>v>>e>>m;
    vector<vector<int> > g(v);
    dp.resize(v,0);
    vis.assign(v,0);
    while(e--) {
        cin>>a>>b;
        g[b].push_back(a);
    }
    cin>>s>>t;
    dp[s] = vis[s] = 1;
    cout<<solve(g,t)<<endl;
    return 0;
}
