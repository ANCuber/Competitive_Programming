#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n;

int dx[4] = {+0,+0,+1,-1};
int dy[4] = {+1,-1,+0,+0};

int check(vector<vector<int> > &h, int g, vector<vector<int> > &vis) {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) vis[i][j] = 0;
    queue<pair<int,int> > q;
    q.push({1,1});
    vis[1][1] = 1;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (abs(h[x][y]-h[x+dx[i]][y+dy[i]]) <= g && !vis[x+dx[i]][y+dy[i]]) {
                vis[x+dx[i]][y+dy[i]] = vis[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout<<vis[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;*/
    return vis[n][n];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    vector<vector<int> > h(n+2,vector<int>(n+2,1e9)), vis(n+2,vector<int>(n+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>h[i][j];
        }
    }
    int l = -1, r = 1e6, mid;
    //for (int i = 1; i <= 15; ++i) cout<<check(h,i,vis)<<' '; cout<<endl;
    while(r-l > 1) {
        mid = (l+r)>>1;
        if (check(h,mid,vis)) r = mid;
        else l = mid;
    }
    cout<<r<<'\n';
    cout<<check(h,r,vis)-1<<'\n';
    return 0;
}
