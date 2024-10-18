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
    vector<int> d(n);
    for (auto& i : d) cin>>i;
    sort(d.begin(),d.end());
    int ans = d[0]*(n-1);
    for (int i = 1; i < n; ++i) {
        ans += d[i];
    }
    cout<<ans<<endl;
    return 0;
}

