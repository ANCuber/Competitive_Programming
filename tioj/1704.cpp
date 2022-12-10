#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Org{
    int sz;
    vector<int> a;
    bool operator<(Org b) {
        return sz < b.sz;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    vector<Org> w(n+1);
    w[0].sz = 0;
    for (int i = 1; i <= n; ++i) cin>>w[i].sz;
    
    for (int i = 1; i <= n; ++i) {
        w[i].a.pb(0);
        for (int j = 1; j <= n; ++j) {
            int x; cin>>x;
            w[i].a.pb(x);
        }
    }
    sort(w.begin(),w.end());

    vector<vector<int> > dp(n+1,vector<int>(n+1,-1e9));
    for (int i = 0; i <= n; ++i) dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {//cnt
        int mx = -1e9, cur = -1e9;
        for (int j = 1; j <= n; ++j) {//id
            mx = max(mx,dp[i-1][j-1]);
            dp[i][j] = mx+w[j].a[i];
            cur = max(dp[i][j],cur);
        }
        if (cur >= k) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
    return 0;
}
