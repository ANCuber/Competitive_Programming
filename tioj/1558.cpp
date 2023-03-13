#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d, r;
    while(cin>>n>>d>>r) {
        vector<int> a(n), b(n);
        for (auto& i : a) cin>>i;
        for (auto& i : b) cin>>i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max(0ll,a[i]+b[i]-d);
        }
        cout<<cnt*r<<endl;
    }
    return 0;
}
