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
    int n, k; cin>>n>>k;    
    vector<int> a(1000005,0), s(1000005,0);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
         int x; cin>>x;
         mx = max(mx,x);
         s[x]++;
         a[x] += x;
    }
    for (int i = 1; i <= 1e6; ++i) a[i] += a[i-1];
    for (int i = 1; i <= 1e6; ++i) s[i] += s[i-1];
    
    int ans = 0;
    for (int i = k; i <= mx; ++i) {
        int cur = 0;
        for (int j = 0; j*i <= mx; ++j) {//j*i~(j+1)*i-1
            //if (j) cout<<s[(j+1)*i-1]-s[j*i-1]<<endl;
            int R = min(1ll*1000000,(j+1)*i-1);
            if (j) cur += a[R]-a[j*i-1]-(s[R]-s[j*i-1])*i*j;
            else cur += a[R]-s[R]*i*j;
        }
        //cout<<i<<' '<<cur<<endl;
        ans = max(a[1000000]-cur,ans);
    }
    cout<<ans<<endl;
    return 0;
}
