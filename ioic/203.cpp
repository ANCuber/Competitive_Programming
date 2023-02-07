#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

const int mod = 998244353;

int power(int a, int n) {
    int ans = 1, base = a;
    while(n) {
        if (n&1) ans = ans*base%mod;
        base = base*base%mod;
        n >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m; cin>>m;    
    int s; cin>>s;
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        if (n < m) {
            cout<<0<<endl;
        } else {
            int num = 1;
            for (int i = 0; i < m; ++i) num *= 10;
            cout<<(n-m+1)%mod*power(num%mod,(mod-2))%mod<<endl;
        }
    }
    return 0;
}
