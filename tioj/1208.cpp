#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

#define int ll

ll check(int l, int r, vector<ll> &a, ll v) {
    if (l == r) return (a[l] > v);
    ll mid = (l+r)/2;
    ll cnt = check(l,mid,a,v)+check(mid+1,r,a,v);
    vector<ll> tmp;
    for (int i = l, j = mid+1; j <= r; ++j) {
        while(a[j]-a[i] > v && i <= mid) {
             cnt += r-j+1;
             i++;
        }
    }
    int lp = l, rp = mid+1;
    while(lp <= mid && rp <= r) {
        if (a[lp] <= a[rp]) tmp.pb(a[lp++]);
        else tmp.pb(a[rp++]);
    }
    while(lp <= mid) tmp.pb(a[lp++]);
    while(rp <= r) tmp.pb(a[rp++]);
    for (int i = 0; i < tmp.size(); ++i) a[l+i] = tmp[i];
    return cnt;
}

void run(int n, int k) {
    vector<ll> a(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] += a[i-1];
    }
    ll l = -2e8-1, r = 2e8;
    while(r-l > 1) {
        ll mid = (l+r)/2;
        vector<ll> ps = a;
        if (check(1,n,ps,mid) >= k) l = mid;
        else r = mid;
    }
    cout<<r<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K;    
    while(cin>>N>>K && N && K) run(N,K);
    return 0;
}


