#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n, d;

int Cal() {
    int x, y, z;
    cin>>x>>y>>z;
    if (max({x,y,z})-min({x,y,z}) >= d) return (x+y+z)/3;
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>d;
    int cnt = 0, ans = 0;
    while(n--) {
        int cur = Cal();
        cnt += (cur > 0);
        ans += cur;
    }
    cout<<cnt<<' '<<ans<<'\n';
    return 0;
}
