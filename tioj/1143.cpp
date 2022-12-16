#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[8] = {1,-1,-3,-3,-1,1,3,3};
int dy[8] = {3,3,1,-1,-3,-3,-1,1};
int cx[8] = {0,0,-1,-1,0,0,1,1};
int cy[8] = {1,1,0,0,-1,-1,0,0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<vector<int> > g(105,vector<int>(105,1)), vis(105,vector<int>(105,0));
    while(n--) {
        int x, y; cin>>x>>y;
        g[x][y] = 0;
    }
    int sx, sy; cin>>sx>>sy;
    int ex, ey; cin>>ex>>ey;
    queue< pii > q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    int ans = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == ex && y == ey) {
            ans = vis[x][y];
            break;
        }
        for (int i = 0; i < 8; ++i) {
            if (x+dx[i] < 0 || x+dx[i] > 99 || y+dy[i] < 0 || y+dy[i] > 99) continue;
            if (g[x+dx[i]][y+dy[i]] && !vis[x+dx[i]][y+dy[i]] && g[x+cx[i]][y+cy[i]]) {
                vis[x+dx[i]][y+dy[i]] = vis[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
    if(ans) cout<<ans-1<<endl;
    else cout<<"impossible\n";
    return 0;
}
