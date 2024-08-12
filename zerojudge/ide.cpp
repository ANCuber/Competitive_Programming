#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int arr[n+5];
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    arr[0] = -1e9;
    arr[n+1] = 1e9;
    int ans = 0, cnt = 0;
    for (int i =1; i <= n; ++i) {
        if (arr[i] < arr[i-1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        ans = max(ans,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
