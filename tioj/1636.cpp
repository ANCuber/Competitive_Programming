#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    ll a; cin>>a;
    if (n == 1) {
        cout<<a*(k>>1)+a<<endl;
        return 0;
    }
    ll ans = 0, sum = a, pre, tmp;
    for (int i = 1, id; i <= min(n-1,k); ++i) {
        pre = a;
        cin>>a;
        sum += a;
        tmp = sum, id = k-i;
        if (id&1) tmp += pre;
        tmp += (id>>1)*(pre+a);
        ans = max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}

