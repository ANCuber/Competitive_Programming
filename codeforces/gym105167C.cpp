#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin>>n>>m;
    cout<<(n*(n-1)/2)*(m*(m-1)/2)<<'\n';
    return 0;
}
