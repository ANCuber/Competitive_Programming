#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int k;

ll power(ll a, ll n) {
    ll ret = 1, base = a;
    while(n) {
        if (n&1) ret = ret*base%k;
        base = base*base%k;
        n >>= 1;
    }
    return ret%k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m; 
    while(cin>>m && m) {
        ll x[m];
        ll ans;
        for (int i = 0; i < m; ++i) {
            cin>>x[i];
        }
        cin>>k;
        for (int i = m-1; i >= 0; --i) {
            if (i == m-1) {
                ans = x[i]%k;
                continue;
            }
            ans = power(x[i]%k,ans%(k-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
