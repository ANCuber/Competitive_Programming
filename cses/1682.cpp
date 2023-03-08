#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

stack<int> stk;
vector<int> in, low, is, dep;
int c = 0, d = 0;

void Tarjan(int u, vector<vector<int> > &g) {
    stk.push(u);
    in[u] = 1;
    low[u] = dep[u] = ++d;
    for (auto v : g[u]) {
        if (!dep[v]) {
            Tarjan(v,g);
            low[u] = min(low[u],low[v]);
        } else if (in[v]) {
            low[u] = min(low[u],dep[v]);
        }
    }
    if (low[u] == dep[u]) {
        c++;
        while(stk.top() != u) {
            is[stk.top()] = c;
            in[stk.top()] = 0;
            stk.pop();
        }
        is[u] = c;
        in[u] = 0;
        stk.pop();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1), nw(n+1);
    in.assign(n+1,0), low.assign(n+1,0), dep.assign(n+1,0), is.assign(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; ++i) if (!dep[i]) Tarjan(i,g);
    //Tarjan(1,1,g);
    if (c == 1) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    vector<int> dg(c+5,0);
    for (int i = 1; i <= n; ++i) {
        for (auto j : g[i]) {
            if (is[i] != is[j]) dg[is[j]]++;
        }
    }
    //for (int i = 1; i <= c; ++i) cout<<dg[i]<<' '; cout<<endl;
    int a = 0, b = 0;
    for (int i = 1; i <= c; ++i) {
        if (!dg[i]) {
            a = i;
            if (i == c) b = i-1;
            else  b = i+1;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (is[i] == a) {
            a = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (is[i] == b) {
            b = i;
            break;
        }
    }
    cout<<b<<' '<<a<<endl;
    return 0;
}
