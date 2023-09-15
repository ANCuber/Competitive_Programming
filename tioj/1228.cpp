#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dfn = 0;
vector<int> arr, sz;
vector<vector<int> > g;

void dfs(int u) {
    arr[u] = ++dfn;
    for (auto& v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
}

struct BIT{
    vector<int> a;
    int N;
    void init(int _n) {
        a.assign(_n+5,0);
        N = _n;
    }
    void mdf(int p, int x) {
        while(p <= N) {
            a[p] += x;
            p += p&-p;
        }
    }
    int sum(int p){
        int ans = 0;
        while(p) {
            ans += a[p];
            p -= p&-p;
        }
        return ans;
    }
} bit;

signed main() {
    int n, q, a, b, m, cmd;
    scanf("%d%d",&n,&q);
    bit.init(n);
    g.resize(n+2);
    vector<int> p(n+2,0), M(n+2,0);
    sz.assign(n+2,1), arr.assign(n+2,0);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d",&a,&b,&m);
        g[++a].pb(++b);
        p[b] = a;
        M[b] = m;
    }
    dfs(1);
    for (int i = 2; i <= n; ++i) bit.mdf(arr[p[i]],M[i]);
    
    while(q--) {
        scanf("%d",&cmd);
        if (!cmd) {
            scanf("%d%d",&a,&m);
            a++;
            bit.mdf(arr[p[a]],-M[a]+m);
            M[a] = m;
        } else {
            scanf("%d",&a);
            a++;
            printf("%d\n",(bit.sum(arr[a]+sz[a]-1)-bit.sum(arr[a]-1))*2);
        }
    }
    return 0;
}
