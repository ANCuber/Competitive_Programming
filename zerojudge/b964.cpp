#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> a(n);
    for (auto &i : a) cin>>i;
    sort(a.begin(),a.end());
    int l = -1, r = -1, flg = 1;
    for (auto i : a) {
        if (i < 60) l = i;
        else if (flg) {
            r = i;
            flg = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<a[i];
    }
    cout<<'\n';
    if (l >= 0) cout<<l<<'\n';
    else cout<<"best case\n";
    if (r >= 0) cout<<r<<'\n';
    else cout<<"worst case\n";
    return 0;
}
