#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int ans = 0;

void dfs(int cur, int d, int p,vector<vector<int> > &g, vector<int> &fa, vector<int> &dep) {
    fa[cur] = p;
    dep[cur] = d;
    for (auto i : g[cur]) {
        if (!fa[i]) {
            dfs(i,d+1,cur,g,fa,dep);
        }
    }
}
    
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > g(n+1);
    vector<int> fa(n+1,0);
    vector<int> dep(n+1,0);
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,-1,g,fa,dep);
    vector< pii > v;
    vector<int> cov(n+1,0);
    for (int i = 1; i <= n; ++i) v.push_back({dep[i],i});
    sort(v.begin(),v.end(),greater< pii >());
    set <int> s;
    for (int i = 0; i < n-1; ++i) {
        int cur = v[i].second;
        if (!cov[cur]) {
            s.insert(fa[cur]);
            cov[cur] = cov[fa[cur]] = 1;
        }
    }
    cout<<s.size()+ans<<endl;
    return 0;
}
