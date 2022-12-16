#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cas = 1, cnt = 0;

void Tarjan(int u, int f, vector<vector<int> > &g, vector<int> &ord, vector<int> &low, set<int> &ans) {
    ord[u] = low[u] = ++cnt;
    int chd = 0;
    for (auto v : g[u]) {
        if (!ord[v]) {
            chd++;
            Tarjan(v,u,g,ord,low,ans);
            low[u] = min(low[u],low[v]);
            if ((!f && chd > 1) || (f && low[v] >= ord[u])) {
                ans.insert(u);
            }
        } else if (v != f) {
            low[u] = min(low[u],ord[v]);
        }
    }
}

void run(int n, int m) {
    vector<vector<int> > g(n+1);
    vector<int> ord(n+1,0), low(n+1,0);
    cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    set<int> ans;
    Tarjan(1,0,g,ord,low,ans);
    cout<<"Case #"<<cas++<<':'<<ans.size();
    if (ans.empty()) cout<<" 0";
    for (auto i : ans) {
        cout<<" "<<i;
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    while(cin>>N>>M && N && M) run(N,M);
    return 0;
}

