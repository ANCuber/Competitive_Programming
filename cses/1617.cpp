#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mod 1000000007

signed main() {
    ll n;
    scanf("%lld",&n);
    ll base = 2, ans = 1;
    while(n) {
        if (n&1) ans = ans*base%mod;
        base = base*base%mod;
        n >>= 1;
    }
    printf("%lld",ans);
    return 0;
}
