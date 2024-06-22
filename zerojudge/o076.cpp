#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x, pr, cnt, ans = 0; cin>>n;    
    for (int i = 0; i < n; ++i) {
        cin>>x;
        if (!i) {
            cnt = 1;
        } else {
            if (x < pr) cnt++;
            else cnt = 1;
        }
        pr = x;
        ans = max(ans,cnt);
    }
    cout<<ans<<'\n';
    return 0;
}
