#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;

int match(int cur, vector<vector<int> > &g, vector<bool> &v, vector<int> &p) {
    for (int i = n+1; i <= (n<<1); ++i) {
        if (!v[i] && g[cur][i]) {
            v[i] = 1;
            if (!p[i] || match(p[i],g,v,p)) {
                p[i] = cur;
                return 1;
            }
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > g(n<<1|1,vector<int>(n<<1|1,0));
    vector<int> p(n<<1|1,0);
    while(m--) {
        int x, y; cin>>x>>y;
        x++, y++;
        g[x][y+n] = g[y+n][x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<bool> v(n<<1|1,0);
        ans += match(i,g,v,p);
    }
    cout<<ans<<endl;
    
    return 0;
}
