#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin>>n>>x;
    map<int,int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    while (n--) {
        int a; cin>>a;
        sum += a;
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
