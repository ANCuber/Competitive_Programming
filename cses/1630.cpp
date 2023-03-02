#pragma GCC optimize("O3")
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
    vector< pii > a(n);
    for (auto& [i,j] : a) cin>>i>>j;
    sort(a.begin(),a.end());
    int sum = 0, ans = 0;
    for (auto [i,j] : a) {
        sum += i;
        ans += j-sum;
    }
    cout<<ans<<endl;
    return 0;
}
