#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int ans = 0;

int dfs(int fa, int cur, vector<vector<int> > &g) {
    p_q <int> pq;
    for (auto i : g[cur]) {
        if (i != fa) pq.push(dfs(cur,i,g));
    }
    if (pq.empty()) {
        ans = max(ans,0);
        return 1;
    } else if (pq.size() == 1) {
        ans = max(ans,pq.top());
        return pq.top()+1;
    } else {
        int tmp = pq.top();
        pq.pop();
        ans = max(ans,tmp+pq.top());
        return tmp+1;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > g(n+1);
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,1,g);
    cout<<ans<<endl;
    return 0;
}
