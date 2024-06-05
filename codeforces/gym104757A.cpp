#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n+5), mx(n+5,0), mn(n+5,1e9);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i <= n; ++i) mx[i] = max(mx[i-1],a[i]);
    for (int i = n; i > 0; --i) mn[i] = min(mn[i+1],a[i]);
    int m = 0;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (mx[i-1] <= a[i] && mn[i+1] > a[i]) {
            m++;
            if (ans.size() < 100) ans.pb(a[i]);
        }
    }
    cout<<m;
    for (int i = 0; i < ans.size(); ++i) cout<<' '<<ans[i];
    cout<<endl;
    return 0;
}
