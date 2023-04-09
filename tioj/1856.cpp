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
        vector<int> a(n);
        for (auto& i : a) cin>>i;
        sort(a.begin(),a.end(),greater<int>());
        int ans = 0;
        for (int i = 1 ;i <= n; ++i) {
            ans += max(0ll,a[i-1]-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
