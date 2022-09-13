#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct Num{
    int x, y, v;
    bool operator<(Num b) {
        return v < b.v;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    vector<Num> pq;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>g[i][j];
            pq.push_back({i,j,g[i][j]});
        }
    }
    sort(pq.begin(),pq.end());
    vector<vector<int> > a(m+2,vector<int>(n+2,0));
    ll ans = 0;
    while(!pq.empty()) {
        Num cur = pq.back();
        pq.pop_back();
        ans += cur.v;
        a[cur.x][cur.y] = cur.v;
        for (int i = 0; i < 4; ++i) {
            ans += a[cur.x+dx[i]][cur.y+dy[i]];
        }
    }
    cout<<ans<<endl;
    return 0;
}
