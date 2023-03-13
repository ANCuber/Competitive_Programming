#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

int power(int a, int n, int m) {
    int ret = 1, base = a;
    while(n) {
        if (n&1) ret = ret*base%m;
        base = base*base%m;
        n >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    while(n--) {
        int a, b, c;
        cin>>a>>b>>c;
        cout<<power(a,power(b,c,mod-1),mod)<<endl;
    }
    
    return 0;
}
