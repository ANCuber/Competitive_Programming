#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> p(n+1);
    int ans = 1;
    for (int i = 1; i <= n; ++i) cin>>p[i];
    for (int i = 1; i < n; ++i) {
        ans = ans*(n+1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
