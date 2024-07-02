#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, s, n, un = 0; 
    cin>>m>>s>>n;
    vector<int> x(n+2);
    for (int i = 1; i <= n; ++i) {
        cin>>x[i];
        un += x[i];
    }
    un = m-un;
    s -= un;
    if (s <= 0) {
        cout<<0<<'\n';
        return 0;
    }
    
    
    
    return 0;
}
