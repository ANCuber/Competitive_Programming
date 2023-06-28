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
    int n, t; cin>>t;
    int ans = 0;
    while(t--) {
        cin>>n;
        ans = 0;
        while(n) {
            ans += n;
            n >>= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
