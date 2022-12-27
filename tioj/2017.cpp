#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

int n;
vector<int> bdr(1000005,1e9);
vector<int> mn(1000005);

void slv(int l, int r, vector< pii > &a) {
    if (l == r) return;
    int mid = (l+r)>>1;
    slv(l,mid,a), slv(mid+1,r,a);
    int lp = l, rp = mid+1;
    mn[r] = a[r].second;
    for (int i = r-1; i > mid; --i) {
        mn[i] = min(mn[i+1],a[i].second);
    }
    vector< pii > tmp;
    while(lp <= mid && rp <= r) {
        if (a[lp].first > a[rp].first) {
            bdr[a[lp].second] = min(bdr[a[lp].second],mn[rp]);
            tmp.pb(a[lp++]);
        } else {
            tmp.pb(a[rp++]);
        }
    }
    while(lp <= mid) tmp.pb(a[lp++]);
    while(rp <= r) tmp.pb(a[rp++]);
    for (int i = 0; i < tmp.size(); ++i) a[i+l] = tmp[i];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;    
    vector< pii > a(n+1,{0,0});
    for (int i = 1; i <= n; ++i) {
        cin>>a[i].first;
        a[i].second = i;
        a[i].first += a[i-1].first;
    }
    slv(0,n,a);
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (bdr[i] == 1e9) continue;
        cnt += n-bdr[i]+1;
    }
    cout<<cnt<<endl;
    return 0;
}
