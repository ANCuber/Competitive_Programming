#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int MXN = 2e5+5;
int ans = 0, n, k;

bitset<200005> rmv;
vector<int> cnt(MXN,0), sz(MXN,0);

int get_size(int u, int f, vector<vector<int> > &g) {
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        sz[u] += get_size(v,u,g);
    }
    return sz[u];
}

int get_cen(int u, int f, int csz, vector<vector<int> > &g) {
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        if (2*sz[v] > csz) return get_cen(v,u,csz,g);
    }
    return u;
}

int cal(int u, int f, int d, int flg ,vector<vector<int> > &g) {
    int mxd = d;
    if (flg == 1) cnt[d]++;
    else if (d <= k) ans += cnt[k-d];
    
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        mxd = max(mxd,cal(v,u,d+1,flg,g));
    }
    return mxd;
}

void CAL(int u, vector<vector<int> > &g) {
    cnt[0] = 1;
    int mxd = 0;
    for (auto v : g[u]) {
        if (rmv[v]) continue;
        mxd = max(mxd,cal(v,u,1,0,g));
        cal(v,u,1,1,g);
    }
    for (int i = 0; i <= mxd; ++i) cnt[i] = 0;
}

void solve(int u, vector<vector<int> > &g) {
    int cen = get_cen(u,0,get_size(u,0,g),g);
    CAL(cen,g);
    rmv[cen] = 1;
    
    for (auto v : g[cen]) {
        if (rmv[v]) continue;
        solve(v,g);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    rmv.reset();
    vector<vector<int> > g(n+2);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    solve(1,g);
    cout<<ans<<endl;
    return 0;
}
