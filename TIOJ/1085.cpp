#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

struct Pt{
    int x, y, z;
};

int X, Y, Z;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,1,-1,0,0};

vector<vector<vector<int> > > g(55,vector<vector<int> > (55,vector<int>(55,1)));
vector<vector<vector<int> > > vis(55,vector<vector<int> > (55,vector<int>(55,0)));

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>X>>Y>>Z;
    for (int i = 1; i <= Z; ++i) {
        for (int j = 1; j <= Y; ++j) {
            for (int k = 1; k <= X; ++k) {
                cin>>g[k][j][i];
            }
        }
    }
    queue< pair<Pt,vector<Pt> > > q;
    if (g[1][1][1]) {
        cout<<"no route\n";
        return 0;
    } else {
        g[1][1][1] = 1;
    }
    int flag = 1;
    Pt st = {1,1,1};
    vector<Pt> stv, ans;
    q.push({st,stv});
    while(!q.empty()) {
        Pt cur = q.front().first;
        vector<Pt> path = q.front().second;
        q.pop();
        if (cur.x == X && cur.y == Y && cur.z == Z) {
            ans = path;
            flag = 0;
            break;
        }
        for (int i = 0; i < 6; ++i) {
            int nwx = cur.x+dx[i], nwy = cur.y+dy[i], nwz = cur.z+dz[i];
            if (!g[nwx][nwy][nwz] && !vis[nwx][nwy][nwz]) {
                vis[nwx][nwy][nwz] = 1;
                path.push_back(cur);
                q.push({{nwx,nwy,nwz},path});
                path.pop_back();
            }
        }
    }
    if (flag) {
        cout<<"no route\n";
        return 0;
    }
    for (auto i : ans) {
        cout<<"("<<i.x<<','<<i.y<<','<<i.z<<")->";
    }
    cout<<"("<<X<<','<<Y<<','<<Z<<')'<<endl;
    return 0;
}
