#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (auto &i : a) cin>>i;
    sort(a.begin(),a.end());
    cout<<a.back()<<'\n';
    return 0;
}
