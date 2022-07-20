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

ull mie(ull b) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n;
    ull dp[1000005];
    dp[1] = 1;
    for (ull i = 2; i <= 1000000; ++i) {
        ull a = dp[i-1]*((i<<2)-2)%mod;
        dp[i] = ;
    }
    
    while(t--) {
        cin>>n;
        if (n&1) cout<<"0"<<endl;
        else cout<<dp[n>>1]<<endl;
    }
    return 0;
}
