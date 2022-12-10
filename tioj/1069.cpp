#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Node{
    int x, y, t;
};

inline int Dis(Node a, Node b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int m;

bool match(int u, vector<int> &p, vector<int> &v, vector<vector<int> > &g) {
    for (auto i : g[u]) {
        if (!v[i]) {
            v[i] = 1;
            if (!p[i] || match(p[i],p,v,g)) {
                p[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    cin>>m;
    vector<Node> a(m+1);
    for (int i = 1; i <= m; ++i) cin>>a[i].t>>a[i].x>>a[i].y;
    vector<vector<int> > g(m+2);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == j) continue;
            if (Dis(a[i],a[j]) <= a[j].t-a[i].t) {
                g[i].pb(j);
            }
            //cout<<Dis(a[i],a[j])<<' '<<(a[j].t-a[i].t)<<' '<<g[i][j]<<'!';
        }
        //cout<<endl;
    }
    int cnt = 0;
    vector<int> p(m+1,0);
    for (int i = 1; i <= m; ++i) {
        vector<int> v(m+1,0);
        cnt += match(i,p,v,g);
    }
    cout<<(m-cnt)<<endl;
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    while(n--) solve();
    return 0;
}
