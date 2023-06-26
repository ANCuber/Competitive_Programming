#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n, k, q; cin>>n>>k>>q;
    int ans = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        if (a <= q) {
            ans += max(0ll,(i-l+1-k+1));
        } else {
            l = i+1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
