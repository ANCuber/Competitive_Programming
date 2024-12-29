#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void Run() {
    int n, x, y, z; cin>>n;
    vector<int> a(n);
    for (auto &i : a) cin>>i;
    
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        y = a[i-1], z = a[i];
        if (y+z>y && y+z>z && y+y>z && z+z>y) cnt++;
        //if (y+z>y && y+z>z) cout<<2<<":"<<i<<endl;
    }
    for (int i = 2; i < n; ++i) {
        x = a[i-2], y = a[i-1], z = a[i];
        if (x+y>z && x+z>y && y+z>x && x+x>y && x+x>z && y+y>z) cnt++;
        //if (x+y>z && x+z>y && y+z>x && x+x>y && x+x>z && y+y>z) cout<<3<<":"<<i<<endl;;
    }
    if (cnt) cout<<"YES\n";
    else cout<<"NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
