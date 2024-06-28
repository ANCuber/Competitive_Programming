#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<pair<int,int> > a(n);
    for (auto &[l,r] : a) cin>>l>>r;
    sort(a.begin(),a.end());
    int L = 0, R = 0, ans = 0;
    for (auto [l,r] : a) {
        //cout<<"Cur:"<<l<<' '<<r<<endl;
        if (l >= R) {
            ans += (R-L);
            //cout<<L<<' '<<R<<endl;
            L = l, R = r;
        } else if (r > R) {
            ans += (l-L);
            //cout<<L<<' '<<l<<endl;
            L = l, R = r;
        }
    }
    ans += (R-L);
    //cout<<L<<' '<<R<<endl;
    cout<<ans<<'\n';
    return 0;
}
