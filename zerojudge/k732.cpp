#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n, m;

bool check(int x, int y, vector<vector<int> > &g) {
    int sum = 0;
    for (int i = x-g[x][y]; i <= x+g[x][y]; ++i) {
        if (i < 0 || i >= n) continue;
        for (int j = y-(g[x][y]-abs(i-x)); j <= y+(g[x][y]-abs(i-x)); ++j) {
            if (j < 0 || j >= m) continue;
            sum += g[i][j];
        }
    }
    return (sum%10) == g[x][y];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    vector<vector<int> > g(n+5,vector<int>(m+5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>g[i][j];
        }
    }
    vector<pair<int,int> > ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check(i,j,g)) ans.push_back({i,j});
        }
    }
    cout<<ans.size()<<'\n';
    for (auto [x,y] : ans) cout<<x<<' '<<y<<'\n';
    return 0;
}

