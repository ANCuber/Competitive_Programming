#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    vector<vector<int> > g(m+2,vector<int>(m+2,0));
    for (int i = 0; i <= m+1; ++i) {
        g[i][0] = g[0][i] = g[i][m+1] = g[m+1][i] = 1;
    }
    int x, y;
    while(n--) {
        cin>>x>>y;
        g[x][y] = 1;
    }
    int stx, sty, edx, edy;
    cin>>stx>>sty>>edx>>edy;
    queue < pii > q;
    q.push({stx,sty});
    g[stx][sty] = 1;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (!g[cur.first+dx[i]][cur.second+dy[i]]) {
                q.push({cur.first+dx[i],cur.second+dy[i]});
                g[cur.first+dx[i]][cur.second+dy[i]] = g[cur.first][cur.second]+1;
            }
        }
    }
    cout<<g[edx][edy]-1<<endl;
    return 0;
}
