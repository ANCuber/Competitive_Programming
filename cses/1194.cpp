#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char dir[5] = {'&','R','L','D','U'};

struct pos{
    int x, y, t;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    int sx, sy;
    vector<vector<int> > g(n+2,vector<int>(m+2,0));
    queue< pii > obs;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin>>x;
            if (x == 'A') {
                sx = i, sy = j;
            } else if (x == '.') {
                g[i][j] = 1;
            } else if (x == 'M') {
                obs.push({i,j});
            }
        }
    }
    int cnt = 0, ex = 0, ey = 0;
    vector<vector<int> > pth(n+2,vector<int>(m+2,0));
    pth[sx][sy] = 1e9;
    queue<pos> q;
    q.push({sx,sy,1});
    while(!q.empty()) {
        pos cur = q.front();
        q.pop();
        
        if (cur.x == 1 || cur.x == n || cur.y == 1 || cur.y == m) {
            ex = cur.x, ey = cur.y;
            break;
        }

        if (cur.t > cnt) {
            cnt++;
            queue< pii > tmp;
            while(!obs.empty()) {
                pii nw = obs.front();
                obs.pop();
                for (int i = 0; i < 4; ++i) {
                    if (g[nw.first+dx[i]][nw.second+dy[i]]) {
                        g[nw.first+dx[i]][nw.second+dy[i]] = 0;
                        tmp.push({nw.first+dx[i],nw.second+dy[i]});
                    }
                }
            }
            obs = tmp;
        }
        
        for (int i = 0; i < 4; ++i) {
            if (g[cur.x+dx[i]][cur.y+dy[i]] && !pth[cur.x+dx[i]][cur.y+dy[i]]) {
                pth[cur.x+dx[i]][cur.y+dy[i]] = i+1;
                q.push({cur.x+dx[i],cur.y+dy[i],cur.t+1});
            }
        }
    }
    if (!ex && !ey) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
        if (ex == sx && ey == sy) {
            cout<<0<<endl;
            return 0;
        }
        int cx = ex, cy = ey;
        vector<char> ans;
        do {
            ans.pb(dir[pth[cx][cy]]);
            int tx = cx, ty = cy;
            cx = cx-dx[pth[tx][ty]-1];
            cy = cy-dy[pth[tx][ty]-1];
        } while(cx != sx || cy != sy);
        cout<<ans.size()<<endl;
        for (int i = ans.size()-1; i >= 0; --i) {
            cout<<ans[i];
        }
        cout<<endl;
    }
    
    return 0;
}
