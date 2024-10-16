#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int a1, a2, a3; cin>>a1>>a2>>a3;
    int b1, b2; cin>>b1>>b2;
    int mx = -1e9;
    for (int i = 0; i <= n; ++i) {//to A
        for (int j = 0; j <= n; ++j) {//to B
            for (int k = 0; k <= n; ++k) {//useless
                if (i+j+k != n) continue;
                int bt_a = -a1*i*i+a2*i-a3;
                int bt_b = (b1/(101-j))+(b2/(j+1));
                bt_b += (b1%(101-j) != 0)+(b2%(j+1) != 0);
                //cout<<i<<' '<<j<<' '<<k<<':'<<bt_a<<' '<<bt_b<<endl;
                mx = max(mx,bt_a+bt_b);
            }
        }
    }
    cout<<mx<<'\n';
    return 0;
}
