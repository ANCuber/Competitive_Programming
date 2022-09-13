#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int n, m, p, q, a, b;

bool check(int x, int y) {
    return (x>=0 && x<n && y>=0 && y<m);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>p>>q>>a>>b;
    a--,b--;
    int dx[8] = {0,0,0,0,p,-p,q,-q};
    int dy[8] = {p,-p,q,-q,0,0,0,0};
    vector<vector<int> > g(n,vector<int>(m)), vis(n,vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>g[i][j];
        }
    }
    queue < pii > q;
    q.push({0,0});
    vis[0][0] = 1;
    int ctrl = 0;
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        if (cx == a && cy == b) {
            ctrl = 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 8; ++i) {
            if (check(cx+dx[i],cy+dy[i]) && !g[cx+dx[i]][cy+dy[i]] && !vis[cx+dx[i]][cy+dy[i]]) {
                q.push({cx+dx[i],cy+dy[i]});
                vis[cx+dx[i]][cy+dy[i]] = vis[cx][cy]+1;
            }
        }
    }
    if (!ctrl) {
        cout<<-1<<endl;
        return 0;
    }
    int ans = vis[a][b]-1;
    ctrl = 0;
    while(!q.empty()) q.pop();
    q.push({a,b});
    vis.assign(n,vector<int>(m,0));
    vis[a][b] = 1;
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        if (cx == n-1 && cy == m-1) {
            ctrl = 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 8; ++i) {
            if (check(cx+dx[i],cy+dy[i]) && !g[cx+dx[i]][cy+dy[i]] && !vis[cx+dx[i]][cy+dy[i]]) {
                q.push({cx+dx[i],cy+dy[i]});
                vis[cx+dx[i]][cy+dy[i]] = vis[cx][cy]+1;
            }
        }
    }
    if (!ctrl) {
        cout<<-1<<endl;
        return 0;
    }
    ans += (vis[n-1][m-1]-1);
    cout<<ans<<endl;


    return 0;
}
