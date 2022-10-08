#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mxn = 1e4+5;

int cnt = 0, d = 0;
vector<int> stk, dfn(mxn,0), low(mxn,0);
vector<set<int> > nw(1);
vector<vector<int> > g(mxn);
map< pii,int > mp;

void tarjan(int fa, int p, vector<vector<int> > &g) {
    low[p] = dfn[p] = ++d;
    stk.pb(p);
    for (auto v : g[p]) {
        if (v == fa && mp[{min(p,v),max(p,v)}] == 1) continue;
        if (!dfn[v]) {
            tarjan(p,v,g);
        }
        low[p] = min(low[p],low[v]);
    }
    if (low[p] == dfn[p]) {
        nw.pb(set<int>());
        cnt++;
        while(stk.back() != p) {
            nw[cnt].insert(stk.back());
            stk.pop_back();
        }
        nw[cnt].insert(stk.back());
        stk.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    int st = 0;
    while(m--) {
        int a, b; cin>>a>>b;
        a++,b++;
        st = a;
        mp[{min(a,b),max(a,b)}]++;
        g[a].pb(b);
        g[b].pb(a);
    }
    if (st) tarjan(0,st,g);
    sort(nw.begin(),nw.end());
    for (int i = 1; i <= cnt; ++i) {
        cout<<i<<':';
        for (auto j : nw[i]) {
            cout<<' '<<j-1;
        }
        cout<<endl;
    }
    return 0;
}

