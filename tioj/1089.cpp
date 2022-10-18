#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k;

bool match(int cur, vector<vector<int> > &g, vector<int> &v, vector<int> &p) {
    for (int i = n+1; i <= (n<<1); ++i) {
        if (g[cur][i] && !v[i]) {
            v[i] = 1;
            if (!p[i] || match(p[i],g,v,p)) {
                p[i] = cur;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<vector<int> > g(n<<1|1,vector<int>(n<<1|1,0));
    vector<int> p(n<<1|1,0);
    while(k--) {
        int u, v; cin>>u>>v;
        g[u][v+n] = g[v+n][u] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> v(n<<1|1,0);
        ans += match(i,g,v,p);
    }
    cout<<ans<<endl;
    return 0;
}
