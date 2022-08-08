#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n, m;
    while(t--) {
        cin>>n>>m;
        vector<vector<int> > g(205,vector<int>(205,0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>g[i][j];
                g[i][j] = 1-g[i][j];
                g[i][j] += g[i-1][j];
            }
        }
        
    }
    return 0;
}





