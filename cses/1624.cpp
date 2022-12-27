#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cnt = 0;

void dfs(int x, int y, vector<vector<int> > &g) {
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int> > g(10,vector<int>(10,0));
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            char x; cin>>x;
            g[i][j] = (x == '*');
        }
    }
    
    return 0;
}
