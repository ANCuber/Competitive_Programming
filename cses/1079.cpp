#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int MXN = 1e6+5;
const int P = 1e9+7;

int f[MXN], invf[MXN];

int power(int a, int k) {
    int ret = 1, bs = a;
    while(k) {
        if (k&1) ret = ret*bs%P;
        bs = bs*bs%P;
        k >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    f[0] = 1;
    invf[0] = P+1;
    for (int i = 1; i <= 1000000; ++i) f[i] = i*f[i-1]%P;
    for (int i = 1; i <= 1000000; ++i) invf[i] = invf[i-1]*power(i,P-2)%P;
    while(n--) {
        int a, b; cin>>a>>b;
        cout<<f[a]*invf[b]%P*invf[a-b]%P<<endl;
    }
    return 0;
}
