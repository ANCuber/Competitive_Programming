#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, n; cin>>x>>n;
    int mx = -101, mn = 101;
    int sm = 0, lr = 0;
    while(n--) {
        int cur; cin>>cur;
        mn = min(mn,cur);
        mx = max(mx,cur);
        (cur > x)?(lr++):(sm++);
    }
    if (lr > sm) cout<<lr<<' '<<mx<<'\n';
    else cout<<sm<<' '<<mn<<'\n';
    return 0;
}

