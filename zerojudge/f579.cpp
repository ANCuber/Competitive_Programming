#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin>>a>>b;
    int n, c; cin>>n;
    vector<int> ext(105,0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        fill(ext.begin(),ext.end(),0);
        while(cin>>c && c) {
            if (c > 0) ext[c]++;
            else ext[-c]--;
        }
        if (ext[a] > 0 && ext[b] > 0) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
