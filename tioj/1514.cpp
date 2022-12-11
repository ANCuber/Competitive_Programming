#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

const ll maxn = 1e6;

void cal(vector<ll> &phi) {
    phi[1] = 1;
    vector<ll> prim;
    vector<bool> vis(maxn+1,0);
    for (ll i = 2; i <= maxn; ++i) {
        if (!vis[i]) {
            prim.pb(i);
            phi[i] = i-1;
        }
        for (auto p : prim) {
            if (p*i > maxn) break;
            vis[i*p] = 1;
            if (i%p) {
                phi[i*p] = phi[i]*(p-1);
            } else {
                phi[i*p] = phi[i]*p;
                break;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<ll> phi(maxn+1,0);
    cal(phi);
    for (int i = 1; i <= maxn; ++i) phi[i] += phi[i-1];
    int n;
    while(cin>>n && n >= 0) {
        if (!n) cout<<0<<endl;
        else cout<<(2*phi[n]+1)<<endl;
    }
    return 0;
}
