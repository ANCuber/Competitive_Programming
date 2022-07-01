#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dfs(int cur, vector<vector< pii > > &g, vector<int> &vis, vector<int> &d) {
    vis[cur] = 1;
    priority_queue <int> p;
    for (auto i : g[cur]) {
        if (!vis[i.first]) {
            p.push(dfs(i.first,g,vis,d)+i.second);
        }
    }
    int maxn;
    if (p.size() > 1) {
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
    vector<vector< pii > > g;
    vector<int> vis;
    vector<int> d;
    while(cin>>n && n) {
        g.clear();
        g.resize(n+1);
        vis.assign(n+1,0);
        d.assign(n+1,0);
        int a, b, w;
        for (int i = 0; i < n-1; ++i) {
            cin>>a>>b>>w;
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }
        dfs(1,g,vis,d);
        cout<<*max_element(d.begin(),d.end())<<endl;
    }
    return 0;
}
