#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll m, n;
    
    while(cin>>m>>n) {
        if (!m && !n) break;
        if (m > n) swap(n,m);
        ll ans = m*(m+1)*(3*n-m+1)/6;
        cout<<ans<<endl;
    }
    return 0;
}