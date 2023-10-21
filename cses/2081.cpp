#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
#define pb push_back

const int MXN = 2e5+5;
vector<int>  g[MXN];
bitset<200005> rmv;
int sz[MXN];
ll cnt[MXN];
ll ans = 0;
int n, k1, k2;
 
int get_size(int u, int f) {
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        sz[u] += get_size(v,u);
    }
    return sz[u];
}
 
int get_cen(int u, int f, int csz) {
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        if (sz[v]*2 > csz) return get_cen(v,u,csz);
    }
    return u;
}
 
int cal(int u, int f, int d, int flg) {
    if (k2-d < 0) return d;
    int mxd = d;
    if (flg) cnt[d]++;
    else ans += cnt[max(0,k1-d)]-cnt[k2-d+1];
    //if (!flg && k2-d >= 0) cout<<u<<"+:"<<cnt[max(0,k1-d)]-cnt[k2-d+1]<<endl;
    for (auto v : g[u]) {
        if (v == f || rmv[v]) continue;
        mxd = max(mxd,cal(v,u,d+1,flg));
    }
    return mxd;
}
 
void CAL(int u) {
    int mxd = 0, pmx = 0, almx = 0;
    cnt[0] = 1;
    for (auto v : g[u]) {
        if (rmv[v]) continue;
        cal(v,u,1,0);//add to ans
        for (int i = 0; i <= almx; ++i) cnt[i] = cnt[i]-cnt[i+1];
        pmx = mxd = cal(v,u,1,1);//mdf
        almx = max(mxd,almx);
        for (int i = almx-1; i >= 0; --i) cnt[i] += cnt[i+1];
    }
    for (int i = 0; i <= almx; ++i) cnt[i] = 0;
}
 
void solve(int u) {
    int cen = get_cen(u,0,get_size(u,0));
    //cout<<"Centroid:"<<cen<<endl;
    CAL(cen);
    rmv[cen] = 1;
    for (auto v : g[cen]) {
        if (rmv[v]) continue;
        solve(v);
    }
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k1>>k2;
    rmv.reset();
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    solve(1);
    cout<<ans<<endl;
    return 0;
}
