#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb emplace_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    int tmp = 0;
    vector<vector<int> > d(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>d[i][j];
            tmp += d[i][j];
            if (i == 1) tmp += d[i][j];
            if (i == n) tmp += d[i][j];
            if (j == 1) tmp += d[i][j];
            if (j == m) tmp += d[i][j];
        }
    }
    
    vector<int> v(1,0), h(1,0);
    for (int i = 1; i < n; ++i) {
        int cur = 0;
        for (int j = 1; j <= m; ++j) cur += d[i][j]+d[i+1][j];
        v.pb(cur);
    }
    for (int i = 1; i < m; ++i) {
        int cur = 0;
        for (int j = 1; j <= n; ++j) cur += d[j][i]+d[j][i+1];
        h.pb(cur);
    }
    
    if (v.size() > 1) sort(v.begin()+1,v.end(),greater<int>());
    if (h.size() > 1) sort(h.begin()+1,h.end(),greater<int>());
    
    for (int i = 1; i < n; ++i) v[i] += v[i-1];
    for (int i = 1; i < m; ++i) h[i] += h[i-1];

    vector<int> ans(n*m+5,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; (i+1)*(j+1) <= n*m; j++) {
            if (i >= n || j >= m) continue;
            ans[(i+1)*(j+1)] = max(ans[(i+1)*(j+1)],v[i]+h[j]);
        }
    }
    for (int i = 1; i <= n*m; ++i) {
        if (i-1) cout<<' ';
        if (ans[i] || i == 1) cout<<ans[i]+tmp;
        else cout<<-1;
    }
    cout<<endl;
    return 0;
}
