#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Edge{
    int u, v, s, t, id;
    bool operator<(Edge y) {
        if (s == y.s) return t < y.t;
        return s < y.s;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;    
    if (M != N-1) return 0;
    vector<Edge> e(M);
    int cnt = 0;
    for (auto &[u,v,s,t,id] : e) {
        cin>>u>>v>>s>>t;
        id = cnt++; 
        
    }
    sort(e.begin(),e.end());
    int cur = 1, ans = 0;
    string f;
    for (int i = 0; i < M; ++i) f = f+'0';
    for (auto &[u,v,s,t,id] : e) {
        if (cur <= t) {
            cur = max(s+1,cur+1);
            f[id] = '1';
        } else {
            ans++;
            f[id] = '0';
        }
    }
    cout<<ans<<endl;
    cout<<f<<endl;
    return 0;
}
