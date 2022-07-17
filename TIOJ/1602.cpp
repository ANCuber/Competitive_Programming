#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<int> > g(n+2,vector<int>(m+2,INT_MIN));
    vector<vector<int> > vis(n+2,vector<int>(m+2,1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>g[i][j];
            vis[i][j] = 0;
        }
    }
    int x, y; cin>>x>>y;
    queue < pii > q;
    vector < pii > ans;
    q.push({++y,++x});
    vis[y][x] = 1;
    while(!q.empty()) {
        pii cur = q.front();
        ans.push_back({cur.second,cur.first});
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (g[cur.first+dx[i]][cur.second+dy[i]] >= g[cur.first][cur.second] 
            && !vis[cur.first+dx[i]][cur.second+dy[i]]) {
                q.push({cur.first+dx[i],cur.second+dy[i]});
                vis[cur.first+dx[i]][cur.second+dy[i]] = 1;
            }
        }
    }
    sort(ans.begin(),ans.end());
    for (auto i : ans) {
        cout<<'('<<i.first-1<<','<<i.second-1<<')'<<endl;
    }
    return 0;
}
