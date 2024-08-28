#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, z; cin>>x>>y>>z;
    vector<int> cnt(12,0);
    cnt[x]++, cnt[y]++, cnt[z]++;
    cout<<*max_element(cnt.begin(),cnt.end());
    for (int i = 10; i > 0; --i) if (cnt[i]) cout<<' '<<i;
    cout<<'\n';
    return 0;
}

