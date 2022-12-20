#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;
int sx, sy, ex, ey;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string dir[4] = {"D","U","R","L"};
string ans;

struct path{
    int x, y;
};

path pth[1005][1005];
string mov[1005][1005];

bool check(vector<vector<int> > &g) {
    queue<path> q;
    q.push({sx,sy});
    pth[sx][sy] = {-1,-1};
    mov[sx][sy] = "$";
    while(!q.empty()) {
        path cur = q.front();
        if (cur.x == ex && cur.y == ey) {
            return 1;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (g[cur.x+dx[i]][cur.y+dy[i]]) {
                q.push({cur.x+dx[i],cur.y+dy[i]});
                pth[cur.x+dx[i]][cur.y+dy[i]] = {cur.x,cur.y};
                mov[cur.x+dx[i]][cur.y+dy[i]] = dir[i];
                g[cur.x+dx[i]][cur.y+dy[i]] = 0;
            }
        }
    }
    return 0;
}

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d%d",&n,&m);
    char s[1000];
    vector<vector<int> > g(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        //string x; cin>>x;
        scanf("%s",s);
        fflush(stdin);
        for (int j = 1; j <= m; ++j) {
            if (s[j-1] == '.' || s[j-1] == 'B') g[i][j] = 1;
            if (s[j-1] == 'A') {
                sx = i, sy = j;
            } else if (s[j-1] == 'B') {
                ex = i, ey = j;
            }
        }
    }
    if (check(g)) {
        cout<<"YES"<<endl; 
        int x = ex, y = ey;
        string ans;
        while(mov[x][y] != "$") {
            ans += mov[x][y];
            int tx = x, ty = y;
            x = pth[tx][ty].x;
            y = pth[tx][ty].y;
        }
        cout<<ans.size()<<endl;
        for (int i = ans.size()-1; i >= 0; --i) {
            cout<<ans[i];
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
    return 0;
}
