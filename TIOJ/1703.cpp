#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll g(ll x) {
    if (!x%3) return 1+g(x/3);
    else return 0;
}

ll f(ll x) {
    if (x <= 0) return 0;
    return g(x)+f(x-1);
}

int main() {
    ll n; cin>>n;
    cout<<f(n)<<endl;
    return 0;
}
