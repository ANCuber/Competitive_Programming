#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    stack <ll,vector<ll> > stk;
    ll ans = 0;
    ll ctrl = 0;
    for (int i = 0; i < n; ++i) {
        ctrl = 0LL;
        while(!stk.empty() && a[i] >= stk.top()) {
            stk.pop();
            ctrl = 1LL;
        }
        stk.push(a[i]);
        ans += ctrl*a[i];
    }
    while(!stk.empty()) stk.pop();
    for (int i = n-1; i >= 0; --i) {
        ctrl = 0LL;
        while(!stk.empty() && a[i] > stk.top()) {
            stk.pop();
            ctrl = 1LL;
        }
        stk.push(a[i]);
        ans += ctrl*a[i];
    }
    cout<<ans<<endl;
    return 0;
}
