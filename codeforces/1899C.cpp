#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<int> a(n+2), dp(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    int ans = a[1], sum = a[1];
    for (int i = 2; i <= n; ++i) {
        if (abs(a[i-1])%2 == abs(a[i])%2 || sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
