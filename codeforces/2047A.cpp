#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int sum = 0, ans = 0;
        while(n--) {
            int a; cin>>a;
            sum += a;
            int sq = sqrt(sum);
            if (sum == sq*sq && (sq&1)) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

