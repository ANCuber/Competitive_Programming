#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define pb push_back

int ans[500005];

void slv(int l, int r, vector< pii > &q, vector<int> &h) {
    if (l == r) {
        for (auto [i,id] : q) ans[id] = l;
        return;
    }
    int mid = (l+r)>>1;
    int mx = 0, cur = 0;
    for (auto i : h) {
        if (i > mid) {
            cur = 0;
        } else {
            cur++;
        }
        mx = max(cur,mx);
    }
    vector< pii > ql, qr;
    for (auto [i,id] : q) {
        if (i <= mx) ql.pb({i,id});
        else qr.pb({i,id});
    }
    if (ql.size()) slv(l,mid,ql,h);
    if (qr.size()) slv(mid+1,r,qr,h);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> h(n);
    for (auto& i : h) cin>>i;
    int Q; cin>>Q;
    vector< pii > q(Q);
    for (int i = 0; i < Q; ++i) {
        cin>>q[i].first;
        q[i].second = i;
    }
    slv(1,1e8,q,h);
    for (int i = 0; i < Q; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
