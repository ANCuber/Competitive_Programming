#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    ll f[20];
    f[1] = 1;
    for (ll i = 2; i < 20; ++i) f[i] = f[i-1]*(4*i-2)/(i+1);
    while(cin>>n) {
        cout<<f[n]<<endl;
    }
    return 0;
}
