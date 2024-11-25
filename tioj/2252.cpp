#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long double a, b, n;
    cin>>a>>b>>n;
    long double x, y, px, py;
    long double ans = 2e9;
    for (int i = 0; i <= n; ++i) {
        cin>>x>>y;
        if (i) {
            long double A = y-py, B = px-x, C = -px*(y-py)+py*(x-px);
            long double dot1 = (x-px)*(x-a)+(y-py)*(y-b), dot2 = (x-px)*(px-a)+(y-py)*(py-b);
            if (dot1*dot2 <= 0) ans = min(ans,abs(A*a+B*b+C)/sqrt(A*A+B*B));
            else ans = min({ans,sqrt((x-a)*(x-a)+(y-b)*(y-b)),sqrt((px-a)*(px-a)+(py-b)*(py-b))});
            //cout<<x<<' '<<y<<':'<<px<<' '<<py<<"->"<<abs(A*a+B*b+C)/sqrt(A*A+B*B)<<endl;
        }
        px = x, py = y;
    }
    cout<<fixed<<setprecision(12);
    cout<<ans<<'\n';
    return 0;
}
