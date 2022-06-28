#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector <ll> pre(n+1,0);
    ll x;
    for (int i = 1; i <= n; ++i) {
        cin>>x;
        ll cur = pre[i-1];
        pre[i] = cur^x;
    }
    int l, r;
    while(q--) {
        cin>>l>>r;
        ll a = pre[r], b = pre[l-1];
        cout<<(a^b)<<endl;
    }
    return 0;
}
