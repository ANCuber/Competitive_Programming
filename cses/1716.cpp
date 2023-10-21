#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MXN = 2e6;
const int P = 1e9+7;

int f[MXN+5], invf[MXN+5];

int power(int a, int x) {
    int ret = 1, bs = a;
    while(x) {
        if (x&1) ret = ret*bs%P;
        bs = bs*bs%P;
        x >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    f[0] = 1;
    for (int i = 1; i <= MXN; ++i) f[i] = i*f[i-1]%P;
    invf[MXN] = power(f[MXN],P-2);
    for (int i = MXN; i > 0; --i) invf[i-1] = invf[i]*i%P;
    cout<<f[n+m-1]*invf[n+m-1-m]%P*invf[m]%P<<endl;
    return 0;
}
