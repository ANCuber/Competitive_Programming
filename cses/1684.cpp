#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, ord = 0, cnt = 0;
stack<int,vector<int> > stk;
vector<int> in, scc, dfn, low;

void Tarjan(int u, vector<vector<int> > &g) {
    stk.push(u);
    in[u] = 1;
    dfn[u] = low[u] = ++ord;
    for (auto v : g[u]) {
        if (!dfn[v]) {
            Tarjan(v,g);
            low[u] = min(low[u],low[v]);
        } else if (in[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        while(stk.top() != u) {
            scc[stk.top()] = cnt;
            in[stk.top()] = 0;
            stk.pop();
        }
        scc[u] = cnt;
        in[u] = 0;
        stk.pop();
    }
}

inline int chg(int x) {
    if (x > m) return x-m;;
    return x+m;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > g(2*m+5), bk(2*m+5);
    in.assign(2*m+5,0), scc.assign(2*m+5,0), dfn.assign(2*m+5,0), low.assign(2*m+5,0);
    vector<int> dg(2*m+5,0);
    for (int i = 1; i <= n; ++i) {
        char a, b; int x, y;
        cin>>a>>x>>b>>y;
        if (a == '-') x += m;
        if (b == '-') y += m;
        g[chg(x)].pb(y);
        g[chg(y)].pb(x);
    }
    for (int i = 1; i <= 2*m; ++i) if (!dfn[i]) Tarjan(i,g);
    
    for (int i = 1; i <= m; ++i) {
        if (scc[i] == scc[chg(i)]) {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i-1) cout<<' ';
        if (scc[i] < scc[chg(i)]) cout<<"+";
        else cout<<"-";
    }
    return 0;
}
