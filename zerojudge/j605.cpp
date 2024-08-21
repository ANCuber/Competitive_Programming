#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int mx = -1, id = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int t, s; cin>>t>>s;
        if (s > mx) {
            mx = s;
            id = t;
        }
        cnt += (s == -1);
    }
    cout<<max(0,mx-n-cnt*2)<<' '<<id<<'\n';
    return 0;
}
