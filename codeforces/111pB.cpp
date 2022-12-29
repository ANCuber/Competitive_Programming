#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> v(n);
    for (auto& i : v) cin>>i;
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i = 0; i < n/2; ++i) {
        ans += v[i];
    }
    cout<<ans<<endl;
    return 0;
}
