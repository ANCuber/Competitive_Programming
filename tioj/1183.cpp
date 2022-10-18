#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char ans[4] = {'R','L','D','U'};

void solve() {
    int n, m; 
    pii s, t;
    cin>>n>>m;
    char x;
    vector<vector<int> > g(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>x;
            if (x == 'S') {s = {i,j}; g[i][j] = 1;}
            else if (x == 'T') {t = {i,j}; g[i][j] = 1;}
            else g[i][j] = (x == '.');
        }
    }
    //return;
    while(s != t) {
        g[s.first][s.second] = 0;
        for (int i = 0; i < 4; ++i) {
            if (g[s.first+dx[i]][s.second+dy[i]]) {
                s = {s.first+dx[i],s.second+dy[i]};
                cout<<ans[i];
                break;
            }
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        solve();
    }
    return 0;
}
