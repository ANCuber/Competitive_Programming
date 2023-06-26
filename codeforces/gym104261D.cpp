#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[9] = {0,0,0,1,1,1,-1,-1,-1};
int dy[9] = {1,-1,0,1,-1,0,1,-1,0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q; cin>>n>>m>>q;    
    int x, y, a, b, c, d;
    vector<vector<int> > g(1005,vector<int>(1005,0));
    while(n--) {
        cin>>x>>y;
        x++, y++;
        g[x][y]++;
    }
    while(m--) {
        cin>>x>>y;
        x++, y++;
        for (int i = 0; i < 9; ++i) {
            g[x+dx[i]][y+dy[i]] = 0;
        }
    }
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            g[i][j] += g[i][j-1];
        }
    }
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            g[i][j] += g[i-1][j];
        }
    }
    while(q--) {
        cin>>a>>b>>c>>d;
        a++, b++, c++, d++;
        cout<<g[c][d]-g[c][b-1]-g[a-1][d]+g[a-1][b-1]<<endl;
    }
    return 0;
}
