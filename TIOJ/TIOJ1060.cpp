#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

map <ll,ll> mpf, mph;

ll g(ll z) {
    if (z <= 2) return z*z-1;
    return 2;
}

ll h(ll y) {
    if (mph.count(y)) return mph[y];
    ll ans;
    if (y < 2) ans = -1;
    else ans = 2+h(y-1)-h(y-2);
    mph[y] = ans;
    return ans;
}

ll f(ll x) {
    if (mpf.count(x)) return mpf[x];
    ll ans;
    if (x > h(x)) {
        ans = f(x-1)-h(x);
    }
    else if (x < h(x)) {
        ans = f(g(x))-g(x);
    }
    else ans = 1;
    mpf[x] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x; cin>>x;
    cout<<f(x)<<endl;
    return 0;
}