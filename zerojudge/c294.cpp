#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin>>a>>b>>c;
    if (c < b) swap(c,b);
    if (c < a) swap(c,a);
    if (a > b) swap(a,b);
    cout<<a<<' '<<b<<' '<<c<<'\n';
    if (a+b <= c) {
        cout<<"No";
    } else if (a*a+b*b == c*c) {
        cout<<"Right";
    } else if (a*a+b*b < c*c) {
        cout<<"Obtuse";
    } else {
        cout<<"Acute";
    }
    cout<<'\n';
    return 0;
}
