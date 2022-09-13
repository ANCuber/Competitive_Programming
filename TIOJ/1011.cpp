#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll ans = 0;

int main() {
    ll a, b; cin>>a>>b;
    int da = 0, db = 0;
    int bfa = a, bfb = b;
    if (a == 0 || b == 0) {
        if (a > b) swap(a,b);
        int ans = 0;
        while(b != 0) {
            b >>= 1;
            ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    while(a != 1) {
        a >>= 1;
        da++;
    }
    while(b != 1) {
        b >>= 1;
        db++;
    }
    a = bfa, b = bfb;
    int ans = da+db;
    while (da > db) {
        da--;
        a >>= 1;
    }
    while(db > da) {
        db--;
        b >>= 1;
    }
    int cp = db;
    while(a != b) {
        a >>= 1;
        b >>= 1;
        cp--;
    }
    cout<<ans-2*cp<<endl;
    return 0;
}
