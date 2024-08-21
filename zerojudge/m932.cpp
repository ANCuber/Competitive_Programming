#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int di[6] = {-1,+0,+1,+1,+0,-1};
int dj[6] = {+0,+1,+1,+0,-1,-1};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n, k;
    cin>>m>>n>>k;
    vector<vector<char> > a(m+5,vector<char>(n+5,'*'));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>a[i][j];
        }
    }
    set<char> s;
    int ci = m, cj = 1;
    while(k--) {
        int x; cin>>x;
        if (ci+di[x] >= 1 && ci+di[x] <= m && cj+dj[x] >= 1 && cj+dj[x] <= n) {
            ci += di[x];
            cj += dj[x];
        }
        cout<<a[ci][cj];
        s.insert(a[ci][cj]);
    }
    cout<<'\n'<<s.size()<<'\n';
    return 0;
}
