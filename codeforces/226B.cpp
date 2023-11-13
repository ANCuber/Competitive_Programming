#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> a(n+1,0);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    sort(a.begin()+1,a.end());
    int A = 0;
    for (int i = 1; i <= n; ++i) A += a[i]*(n-i);
    for (int i = 1; i <= n; ++i) a[i] += a[i-1];
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        if (i) cout<<' ';
        int k; cin>>k;
        if (k == 1) {
            cout<<A;
            continue;
        }
        int ans = 0;
        for (int R = n, c = 1, m = 0; R > 0; m++, R -= c, c *= k) {
            ans += (a[R]-a[max(0ll,R-c)])*m;
            //cout<<R<<' '<<R-c<<endl;
        }
        cout<<ans;
    }
    cout<<endl;
    return 0;
}
