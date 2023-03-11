#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

stack<int,vector<int> > stk;
int n, m;

void dfs(int u, vector<multiset<int> > &g) {
    while(!g[u].empty()) {
        int v = *g[u].begin();
        g[u].erase(g[u].begin());
        dfs(v,g);
    }
    stk.push(u);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;    
    vector<int> dg(n+1,0), out(n+1,0);
    vector<multiset<int> > g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v;
        g[u].insert(v);
        dg[v]++, out[u]++;
    }
    int flag = 0;
    for (int i = 2; i < n; ++i) {
        if (dg[i] != out[i]) {
            flag = 1;
            break;
        }
    }
    if (flag || (out[1]-dg[1]) != 1 || (dg[n]-out[n]) != 1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    dfs(1,g);
    if (stk.size() != m+1) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> ans;
    while(stk.size()) {
        if (stk.size() != m+1) cout<<' ';
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
    return 0;
    for (int i = ans.size()-1; i >= 0; --i) {
        if (i != ans.size()-1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
