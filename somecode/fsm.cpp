#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<vector<int> > ns(n,vector<int>(m)), ot(n,vector<int>(m)), imp(n,vector<int>(n,1));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin>>ns[i][j];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin>>ot[i][j];
    vector<queue<pair<int,int> > > q(2);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            q[0].push({i,j});
        }
    }
    int cnt = 0, tmp = 1;
    while(tmp) {
        tmp = 0;
        while(!q[cnt].empty()) {
            auto cur = q[cnt].front();
            q[cnt].pop();
            int flg = 0;
            for (int j = 0; j < m; ++j) {
                int ca = ns[cur.first][j];
                int cb = ns[cur.second][j];
                if (ca > cb) swap(ca,cb);
                if (ot[cur.first][j] != ot[cur.second][j] || !imp[ca][cb]) {
                    imp[cur.first][cur.second] = 0;
                    tmp++;
                    flg = 1;
                    break;
                }
            }
            if (!flg) q[cnt^1].push(cur);
        }
        cnt = cnt^1;
    }

    vector<pair<int,int> > ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (imp[i][j]) ans.push_back({i,j});
            //cout<<imp[i][j]<<' ';
        }
        //cout<<endl;
    }
    
    sort(ans.begin(),ans.end());
    if (ans.empty()) cout<<"Emo Everyday\n";
    for (auto& [i,j] : ans) cout<<i<<' '<<j<<'\n';
    return 0;
}
