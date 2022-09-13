#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        if (cin.fail()) break;
        ll k; cin>>k;
        n--;
        while(n--) {
            ll x; cin>>x;
            k = (k^x);
        }
        cout<<k<<endl;
    }
    return 0;
}

