#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ll n;
    ll ans = 0;
    while(cin>>n) {
        ans = 0;
        ll tmp = 3;
        while(n >= tmp) {
            ans += n/tmp;
            tmp *= 3;
        }
        cout<<ans<<endl;
    }
    return 0;
}
