#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<int> x(n+2), w(q+2), mx(q+2,0), mn(q+2,0), ans(n+2,0);
    for (int i = 1; i <= n; ++i) cin>>x[i];
    int cur = 0;
    for (int i = 1; i <= q; ++i) {
        cin>>w[i];
        cur += w[i];
        mn[i] = min(mn[i-1],cur);
        mx[i] = max(mx[i-1],cur);
    }
    
    ans[1] += abs(mn[q]);
    ans[n] += mx[q];
    for (int i = 2; i <= n; ++i) {
        int tmp = x[i]-x[i-1];
        int l = 0, r = q+1;
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (mx[mid]+abs(mn[mid]) <= tmp) l = mid;
            else r = mid;
        }
        ans[i-1] += mx[l];
        ans[i] += abs(mn[l]);
        if (l == q) continue;
        if (w[r] >= 0) ans[i-1] += tmp-mx[l]+mn[l];
        else ans[i] += tmp-mx[l]+mn[l];
    }
    for (int i = 1; i <= n; ++i) cout<<ans[i]<<endl;
    return 0;
}
