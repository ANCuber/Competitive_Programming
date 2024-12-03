#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<int> a(n), cnt(n,0);
    for (auto &i : a) cin>>i;
    int mn = 1e9+5, mdfmn = 1e9+5, id = n;
    bool flg = 0;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] > mn) {
            if (!flg) {
                id = i;
                flg = 1;
            }
            cnt[i] = 1;
            mdfmn = min(mdfmn,a[i]);
        }
        mn = min(mn,a[i]);
    }
    for (int i = id+1; i < n; ++i) {
        if (a[i] > mdfmn+1) cnt[i] = 1;
    }
    for (int i = 0; i < n; ++i) a[i] += cnt[i];
    
    sort(a.begin(),a.end());
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout<<a[i];
    }
    cout<<'\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
