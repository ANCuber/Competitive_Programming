#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

int power(int a, int x) {
    int ans = 1, bs = a;
    while(x) {
        if (x&1) ans = ans*bs%mod;
        bs = bs*bs%mod;
        x >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    int ans;
    vector<int> f(1000005), inv(1000005), rf(1000005);
    f[1] = 1;
    for (int i = 2; i <= 1e6; ++i) f[i] = f[i-1]*i%mod;
    for (int i = 1; i <= 1e6; ++i) inv[i] = power(i,mod-2);
    rf[1] = inv[1];
    for (int i = 2; i <= 1e6; ++i) rf[i] = rf[i-1]*inv[i]%mod;
    while(cin>>n>>k) {
        if (k==1) {
            cout<<0<<endl;
        } else {
            ans = 0;
            for (int i = 2; i <= k; ++i) {
                if (k%i || n%i) continue;
                ans += f[n]*rf[n/i]%mod*power(inv[i],n/i)%mod;
                ans %= mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
