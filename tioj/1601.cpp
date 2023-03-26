#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cas = 0;
int n, m;

void solve() {
    vector<ROW> g(n+2, vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>g[i][j];
        }
    }
    
    
    
    int mx = 0;
    for (int i = 1; i <= n; ++i) mx = max(mx,i+cnt[i]);
    cout<<"Case "<<(++cas)<<": "<<mx*2<<endl;
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>m) {
        solve();
    }
    return 0;
}
