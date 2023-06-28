#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    sort(a.begin(),a.end());
    int ans = 0;
    for (int i = 0; i < n/2; ++i) {
        ans += (a[n-i-1]-a[i]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
