#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

int power(int x, int k) {
    int a = 1, bs = x;
    while(k) {
        if (k&1) a = a*bs%mod;
        bs = bs*bs%mod;
        k >>= 1;
    }
    return a;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int num = 1, sum = 1, prd = 1, tot = 1;
    vector<pii> pri(n);
    for (int i = 0; i < n; ++i) {
        int x, k; cin>>x>>k;
        pri[i] = {x,k};
        num = num*(k+1)%mod;
        sum = sum*((power(x,k+1)-1+mod)%mod*power(x-1,mod-2)%mod)%mod;
        tot = tot*(k+1)%mod;
    }
    for (int i = 0; i < n; ++i) {
        
    }
    cout<<num<<' '<<sum<<' '<<prd<<endl;
    return 0;
}
