#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int mp[5][5] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char mrk[4] = {'D','U','R','L'};

void dfs(int x, int y, int u) {
    for (int i = 0; i < 4; ++i) {
        if (mp[x+dx[i]][y+dy[i]] == u+1) {
            cout<<mrk[i];
            dfs(x+dx[i],y+dy[i],u+1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<"*";
    int sx, sy;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin>>mp[i][j];
            if (mp[i][j] == 1) {
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx,sy,1);
    cout<<endl;
    return 0;
}
