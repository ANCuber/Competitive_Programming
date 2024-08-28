#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int s, t, n, m, r;
    cin>>s>>t>>n>>m>>r;
    vector<vector<int> > A(s+2,vector<int>(t+2,0)), B(n+2,vector<int>(m+2,0));
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < t; ++j) {
            cin>>A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>B[i][j];
        }
    }
    int ans = 0, mn = 1e9;
    for (int i = 0; i+s-1 < n; ++i) {
        for (int j = 0; j+t-1 < m; ++j) {
            int cnt = 0, dif = 0;
            for (int x = 0; x < s; ++x) {
                for (int y = 0; y < t; ++y) {
                    cnt += (A[x][y] != B[i+x][j+y]);
                    dif += (A[x][y]-B[i+x][j+y]);
                }
            }
            if (cnt <= r) {
                ans++;
                mn = min(mn,abs(dif));
            }
        }
    }
    if (ans) cout<<ans<<'\n'<<mn<<'\n';
    else cout<<"0\n-1"<<'\n';
    return 0;
}
