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
    int t; cin>>t;    
    while(t--) {
        int n; cin>>n;
        int ans = 0;
        vector<int> a(n);
        for (auto& i : a) cin>>i;
        sort(a.begin(),a.end());
        for (int i = n-2; i >= 0; i -= 2) {
            //cout<<a[i]<<' ';
            ans += a[i]*4;
        }
        cout<<ans<<endl;
    }
    return 0;
}
