#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;
    map<int,int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    while(n--) {
        int a; cin>>a;
        sum += a;
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
