#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<vector<int>> q(200005);
vector<int> tg(200005,0), dp(200005,-1), chd(200005);
bitset<200005> nxt, in;

int cnt = 0, cur = 0;

void Pre(int u, int f, vector<vector<int> > &g) {
    in[u] = 1;
    for (auto i : q[u]) {
        if (in[i]) {//LCA(u,v) = v
            nxt[chd[i]] = 0;
            //tg[1]++;
            //tg[chd[i]]--;
        } else {
            tg[i]++;
            cnt++;
        }
    }
    for (auto v : g[u]) {
        if (v == f) continue;
        chd[u] = v;
        Pre(v,u,g);
    }
    in[u] = 0;
}

void Dfs(int u, int f, vector<vector<int> > &g) {
    if (!nxt[u]) return;
    cur += tg[u];
    dp[u] = cur;
    for (auto v : g[u]) {
        if (v == f) continue;
        Dfs(v,u,g);
    }
    cur -= tg[u];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    nxt.set(), in.reset();
    vector<vector<int> > g(n+2);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int Q; cin>>Q;
    for (int i = 0; i < Q; ++i) {
        int a, b; cin>>a>>b;
        q[b].pb(a);
    }
    Pre(1,0,g);
    Dfs(1,0,g);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == cnt && dp[i] >= 0) ans.pb(i);
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}

