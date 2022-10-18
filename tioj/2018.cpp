#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll v; cin>>v;
    ll mn = 1e18, x, y, z;
    for (ll i = 1; i <= (ll)(pow(v,1.0/3))+1; ++i) {
        if (v%i) continue;
        ll cur = v/i;
        for (ll j = (ll)(sqrt(cur)); j > 0; --j) {
            if (cur%j) continue;
            if (mn > i*j+j*(cur/j)+(cur/j)*i) {
                mn = i*j+j*(cur/j)+(cur/j)*i;
                x = i, y = j, z = cur/j;
            }
            break;
        }
    }
    cout<<(mn<<1)<<' '<<x<<' '<<y<<' '<<z<<endl; 
    return 0;
}

