#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, r; cin>>n>>r;
    vector<vector<int> > a(n+2,vector<int>(n+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>a[i][j];
        }
    }
    while(r--) {
        vector<vector<int> > tmp(n+2,vector<int>(n+2,0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) cnt += a[i+dx[k]][j+dy[k]];
                if (a[i][j]) tmp[i][j] = (cnt == 2 || cnt == 3);
                else tmp[i][j] = (cnt == 3);
            }
        }
        a = tmp;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j-1) cout<<' ';
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
