#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[3] = {1,-1,0};
int dy[3] = {0,0,1};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    int s, t; cin>>s>>t;
    s++, t++;
    vector<vector<int> > g(n+5,vector<int> (m+5,-1));
    for (int i = 1; i <= n; ++i) {
        string s; cin>>s;
        for (int j = 1; j <= m; ++j) {
            g[i][j] = s[j-1]-'0';
        }
    }
    
    return 0;
}
