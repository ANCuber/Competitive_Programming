#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>m>>n;
    vector<string> a(n);
    for (auto &i : a) cin>>i;
    map<string,int> mp;
    set<string> s;
    for (int i = 0; i < m; ++i) {
        mp[a[i]]++;
        if (mp[a[i]] > 1) s.insert(a[i]);
    }
    int ans = (s.size() == 0);
    for (int i = 1; i+m-1 < n; ++i) {
        if (mp[a[i-1]] == 2) s.erase(s.find(a[i-1]));
        mp[a[i-1]]--;
        mp[a[i+m-1]]++;
        if (mp[a[i+m-1]] > 1) s.insert(a[i+m-1]);
        ans += (s.size() == 0);
    }
    cout<<ans<<'\n';
    return 0;
}
