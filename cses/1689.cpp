#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int flag = 0;
int g[10][10] = {0};
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

inline bool bd(int x, int y) {
    if (1 <= x && x <= 8 && 1 <= y && y <= 8) return 1;
    return 0;
}

bool check(int x, int y) {
    int cnt = 0;
    for (int k = 0; k < 8; ++k) {
        if (!bd(x+dx[k],y+dy[k])) continue;
        if (!g[x+dx[k]][y+dy[k]]) cnt = 1;
    }
    return cnt;
}

void dfs(int x, int y, int cnt) {
    if (flag) return;
    if (cnt == 64) {
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) {
                if (j != 1) cout<<' ';
                cout<<g[j][i];
            }
            cout<<endl;
        }
        flag = 1;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        if (!bd(x+dx[i],y+dy[i])) continue;
        if (!check(x+dx[i],y+dy[i])) continue;
        if (!g[x+dx[i]][y+dy[i]]) {
            g[x+dx[i]][y+dy[i]] = cnt+1;
            dfs(x+dx[i],y+dy[i],cnt+1);
            g[x+dx[i]][y+dy[i]] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y; cin>>x>>y;    
    g[x][y] = 1;
    dfs(x,y,1);
    return 0;
}
