#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<ll> a(n+2,0);
    ll cur = 0, md = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        md += a[i];
        cur += a[i]*i;
    }
    for (int x = 0; x <= max(1,n/2); ++x) {
        cur -= (a[x]*x+a[n-x+1]*(n-x+1));
        cur += (a[x]*(n-x+1)+a[n-x+1]*x);
        if (cur%md == 0) {
            cout<<x<<' ';
            cout<<cur/md-1<<endl;
            return 0;
        }
    }
    return 0;
}
