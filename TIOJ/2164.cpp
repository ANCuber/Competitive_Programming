#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int ll

struct shop{int x, y, z;};

int dis(shop a, shop b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int ans = 0;
    vector<shop> a(n);
    vector<bool> vis(n,0);
    vector<int> d(n,1e18);
    vector<vector<int> > g(n,vector<int>(n,0));
    for (int i = 0; i < n; ++i) cin>>a[i].x>>a[i].y>>a[i].z;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = dis(a[i],a[j]);
        }
    }
    vis[0] = 1;
    for (int i = 0; i < n; ++i) d[i] = min(d[i],g[0][i]);
    for (int i = 1; i < n; ++i) {
        int mn = 1e18;
        int to = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && mn > d[j]) {
                to = j;
                mn = d[j];
            }
        }
        
        ans += mn;
        vis[to] = 1;
        for (int j = 0; j < n; ++j) {
            d[j] = min(d[j],g[to][j]);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
