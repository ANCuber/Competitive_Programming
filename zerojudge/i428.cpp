#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int px = 0, py = 0, mx = -1, mn = 1e9;
    for (int i = 0; i < n; ++i) {
        int x, y; cin>>x>>y;
        if (i) {
            int cur = abs(x-px)+abs(y-py);
            mx = max(mx,cur);
            mn = min(mn,cur);
        }
        px = x, py = y;
    }
    cout<<mx<<' '<<mn<<'\n';
    return 0;
}

