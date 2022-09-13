#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m; cin>>m;
    ll a, b, c;

    while(m--) {
        cin>>a>>b>>c;
        ll d = b*b-4*a*c;
        ll x = lround(sqrt(d));
        if (x*x == d) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
