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
    int x = 1, b = a;
    while(n) {
        if (n&1) x = x*b%mod;
        b = b*b%mod;
        n >>= 1;
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n+1);
    int a1, sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum += a[i];
    }
    a1 = a[1];
    int m; cin>>m;
    int up = 0;
    for (int i = 1; i <= m; ++i) {
        int c; cin>>c;
        a1 = a1*(sum+c)%mod*power(sum,mod-2)%mod;
        sum += c;
    }
    cout<<a1<<endl;
    return 0;
}
