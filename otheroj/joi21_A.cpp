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
    int n; cin>>n; 
    vector<int> a(n+2);
    vector<int> dp1(n+2), dp2(n+2), lk1(n+2), lk2(n+2), h1(n+2), h2(n+2), mx1(n+2), mx2(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    
    dp1[1] = lk1[1] = dp2[n] = lk2[n] = 0;
    h1[1] = a[1];
    h2[n] = a[n];
    for (int i = 2; i <= n; ++i) {
        lk1[i] = max(max(a[i],h1[i-1]+1)-a[i],lk1[i-1]);
        h1[i] = a[i]+lk1[i];
        
        dp1[i] = dp1[i-1]+max(0ll,lk1[i]-mx1[i-1]);
        mx1[i] = max(mx1[i-1],lk1[i]);
        //cout<<lk1[i]<<' '<<dp1[i]<<' '<<h1[i]<<endl;
    }
    for (int i = n-1; i > 0; --i) {
        lk2[i] = max(max(a[i],h2[i+1]+1)-a[i],lk2[i+1]);
        h2[i] = a[i]+lk2[i];

        dp2[i] = dp2[i+1]+max(0ll,lk2[i]-mx2[i+1]);
        mx2[i] = max(mx2[i+1],lk2[i]);
        //cout<<lk2[i]<<' '<<dp2[i]<<' '<<h2[i]<<endl;
    }
    
    int ans = min(dp2[1],dp1[n]);
    for (int i = 2; i <= n; ++i) {
        int tmp = dp1[i-1]+dp2[i]-min(lk1[i-1],lk2[i]);
        if (h1[i-1] == h2[i] && lk1[i-1] == lk2[i]) {
            if (!(mx1[i-2] > lk1[i-1] || mx2[i+1] > lk2[i])) tmp++;
        }
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
