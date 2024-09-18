#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    string a, b; cin>>a>>b;
    vector<int> cnt(30,0);
    for (int i = 0; i < m; ++i) cnt[b[i]-'a'] = 1;
    for (int i = 0; i < n; ++i) {
        if (!cnt[a[i]-'a']) {
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
