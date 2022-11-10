#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

ll n, a1, b1, c1, a2, b2, c2;

ll f(ll x) {
    return a1*x*x+b1*x+c1+a2*(n-x)*(n-x)+b2*(n-x)+c2;
}

signed main() {
    scanf("%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&a2,&b2,&c2,&n);
    ll ans = -2e18;
    for (ll i = 0; i <= n; ++i) {
        ans = max(ans,f(i));
    }
    printf("%lld",ans);
    return 0;
}
