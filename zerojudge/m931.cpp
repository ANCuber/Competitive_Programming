#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int a, d;
    int mxa = 0, mxd = 0, sea = 0, sed = 0, mx = 0, se = 0;
    for (int i = 0; i < n; i++) {
        cin>>a>>d;
        int cur = a*a+d*d;
        if (cur >= mx) {
            se = mx;
            mx = cur;
            sea = mxa;
            sed = mxd;
            mxa = a;
            mxd = d;
        } else if (cur >= se) {
            se = cur;
            sea = a;
            sed = d;
        }
        //cout<<mxa<<' '<<mxd<<':'<<sea<<' '<<sed<<endl;
    }
    cout<<sea<<' '<<sed<<'\n';
    return 0;
}
