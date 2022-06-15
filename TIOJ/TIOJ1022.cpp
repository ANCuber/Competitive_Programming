#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Place{
    int x, y;
    int turn;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k; cin>>k;
    int m, n;
    while(k--) {
        cin>>m>>n;
        vector<vector<int> >graph(m+2,vector<int>(n+2,200));
        vector<vector<int> >vis(m+2,vector<int>(n+2,0));
        queue <Place> q;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin>>graph[i][j];
            }
        }
        Place s;
        s.x = s.y = 1;
        s.turn = 0;
        q.push(s);
        int ctrl = 1;
        while(!q.empty() && ctrl) {
            Place cur = q.front();
            q.pop();
            vis[cur.x][cur.y] = 1;
            for (int i = 0; i < 4; ++i) {
                if (abs(graph[cur.x][cur.y]-graph[cur.x+dx[i]][cur.y+dy[i]]) <= 5
                && !vis[cur.x+dx[i]][cur.y+dy[i]]) {
                    if (cur.x+dx[i] == m && cur.y+dy[i] == n) {
                        cout<<cur.turn+1<<endl;
                        ctrl = 0;
                        break;
                    }
                    Place nex;
                    nex.x = cur.x+dx[i];
                    nex.y = cur.y+dy[i];
                    nex.turn = cur.turn+1;
                    q.push(nex);
                }
            }
        }
    }
}