#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+9;

int n, m, q, l;    

void mul(vector<vector<int> > &t, vector<vector<int> > a, vector<vector<int> > b) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            t[i][j] = 0;
            for (int k = 1; k <= n; ++k) {
                t[i][j] = (t[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
}

void power(vector<vector<int> > &ans, vector<vector<int> > &g, int k) {
    while(k) {
        if (k&1) mul(ans,ans,g);
        mul(g,g,g);
        k >>= 1;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>q>>l;
    vector<vector<int> > g(n+2,vector<int>(n+2,0)), ans(n+2,vector<int>(n+2,0));
    for (int i = 1; i <= n; ++i) ans[i][i] = 1;
    while(m--) {
        int u, v; cin>>u>>v;
        g[++u][++v]++;
    } 
    power(ans,g,l);
    while(q--) {
        int s, t; cin>>s>>t;
        cout<<ans[++s][++t]<<endl;
    }
    return 0;
}
