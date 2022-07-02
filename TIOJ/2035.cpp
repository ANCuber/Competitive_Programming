#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

ll power(ll x, ll y) {
    ll ret = 1;
    while(y) {
        if (y & 1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll b, n;
    cin>>b>>n;
    ll base = 1;
    ll tn = 0, ctr = 0, a = 0;
    ll bfr = n;
    while(n) {
        tn += base*(n%10);
        n /= 10;
        base *= b;
        ctr++;
    }
    n = bfr;
    while(n) {
        a += power(n%10,ctr);
        n /= 10;
    }
    if (a == tn) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;

}
