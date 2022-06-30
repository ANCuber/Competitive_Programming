#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dfs(int cur, int pre, vector<vector< pii > > &g, vector<int> &vis, vector<int> &d) {
    vis[cur] = 1;
    priority_queue <int> p;
    for (auto i : g[cur]) {
        if (!vis[i.first]) {
            p.push(dfs(i.first,cur,g,vis)+i.second);
        }
    }
    int maxn;
    if (p.size()) {
        int ret = 0;
        ret += p.top();
        maxn = p.top();
        p.pop();
        ret += p.top();
        d[cur] = ret;
    } else if (p.size() == 1) {
        d[cur] = maxn = p.top();
    } else {
        d[cur] = maxn = 0;
    }
    return maxn;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector<vector< pii > > g(n+1);
        vector<int> vis(n+1,0);
        vector<int> d(n+1,0);
        int a, b, w;
        for (int i = 0; i < n; ++i) {
            cin>>a>>b>>w;
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }
        cout<<dfs(1,0,g,vis)<<endl;
    }
    return 0;
}
