#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<int> a(n), b;
    for (auto &i : a) cin>>i;
    sort(a.begin(),a.end());
    for (int i = 1; i < n; ++i) if (a[i]%a[0]) b.pb(a[i]);
    for (int i = 1; i < b.size(); ++i) {
        if (b[i]%b[0]) {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
