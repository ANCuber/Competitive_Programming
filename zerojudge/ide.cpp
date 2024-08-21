#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll ans = 0;

void dfs(int f) {
    int x; cin>>x;
    if (x == 0) return;
    if (f != -1) ans += abs(x-f);
    
    if (x%2 == 0) {
        dfs(x); dfs(x);
    } else {
        dfs(x); dfs(x); dfs(x);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    dfs(-1);
    cout<<ans<<'\n';
    return 0;
}
