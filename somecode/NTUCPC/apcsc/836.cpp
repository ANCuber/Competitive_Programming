#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin>>n>>x;
    int ans = 0, buy = x;
    for (int i = 1; i <= n; ++i) {
        int a; cin>>a;
        ans += min(a,x);
        x = max(0,x-a);
        if (i == n) {
            cout<<ans<<' '<<x<<'\n';
            break;
        }
        (x > 0)?(buy = max(0,buy-1)):(buy++);
        x += buy;
    }
    return 0;
}

