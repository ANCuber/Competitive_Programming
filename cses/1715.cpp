#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int MXN = 1e6;
const int P = 1e9+7;

int f[MXN+5], invf[MXN+5];

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
    string s; cin>>s;
    f[0] = 1;
    for (int i = 1; i <= MXN; ++i) f[i] = f[i-1]*i%P;
    invf[MXN] = power(f[MXN],P-2);
    for (int i = MXN; i > 0; --i) invf[i-1] = i*invf[i]%P;
    map<char,int> mp;
    for (auto c : s) mp[c]++;
    int ans = 1, cnt = 0;
    for (auto [i,j] : mp) {
        ans = ans*invf[j]%P;
        cnt += j;
    }
    cout<<ans*f[cnt]%P<<endl;
    
    return 0;
}
