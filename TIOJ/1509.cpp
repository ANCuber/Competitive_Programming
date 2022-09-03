#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int long long

int m, n;

void dks(vector<vector<pii> > &g, vector<int> &dis) {
    p_q < pii > pq;
    pq.push({0,1});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (auto i : g[cur]) {
            //cout<<cur<<':'<<i.first<<endl;
            if (dis[i.first] > dis[cur]+i.second) {
                dis[i.first] = dis[cur]+i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
}

int cal(vector<int> &dis) {
    int ret = 0;
    for (int i = 1; i <= m; ++i) {
        if(dis[i] == 1e9) return 0;
        ret += dis[i];
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;    
    vector<vector< pii > > g(m+1), bg(m+1);
    vector<int> dis(m+1,1e9);
    dis[1] = 0;
    int p, q, r;
    while(n--) {
        cin>>p>>q>>r;
        g[p].push_back({q,r});
        bg[q].push_back({p,r});
    }
    dks(g,dis);
    int ans = cal(dis);
    if (!ans) {
        cout<<0<<endl;
        return 0;
    }
    dis.assign(m+1,1e9);
    dis[1] = 0;
    dks(bg,dis);
    int a2 = cal(dis);
    if (!a2) {
        cout<<0<<endl;
        return 0;
    }
    cout<<ans+a2<<endl;
    return 0;
}
