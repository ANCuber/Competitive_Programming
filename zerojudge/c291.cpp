#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans = 0; cin>>n;
    vector<int> a(n), vis(n,0);
    for (auto &i : a) cin>>i;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        ans++;
        int cur = i;
        while(!vis[cur]) {
            vis[cur] = 1;
            cur = a[cur];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
