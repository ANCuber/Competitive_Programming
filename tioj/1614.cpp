#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    int ans = 0;
    int a[n];
    vector<int> b(m);
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < m; ++i) cin>>b[i]; 
    sort(b.begin(),b.end());
    for (int i = 0; i < n; ++i) {
        vector<int>::iterator iter = lower_bound(b.begin(),b.end(),a[i]);
        if (*iter == a[i]) continue;
        if ((b.end()-iter+1)&1) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
