#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

const ull mod = 1e9+7;
// (a/b)%mod = a%mod*inv(b)%mod

ull mie(ull a, ull p, ull am, ull an, ull pm, ull pn) {
    if (!p) return am;
    return mie(p,a%p,pm,pn,am-(pm*(a/p)),an-(pn*(a/p)));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n;
    ull dp[1000005];
    dp[1] = 1;
    for (ull i = 2; i <= 1000000; ++i) {
        ull a = dp[i-1]*((i<<2)-2)%mod;
        ull ret = mie(i+1,mod,1,0,0,1)+mod;
        ret %= mod;
        dp[i] = (a*ret)%mod;
    }
    
    while(t--) {
        cin>>n;
        if (n&1) cout<<"0"<<endl;
        else cout<<dp[n>>1]<<endl;
    }
    return 0;
}
