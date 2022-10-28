#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k, Q;
int mx = -1e9-5, cmax = -1e9-5;
int arr[500005];
int ans[500005];

struct Query{
    int ql, qr, id;
    bool operator<(Query b) {
        if (ql/k == b.ql/k) return qr < b.qr;
        return ql/k < b.ql/k;
    }
} q[500005];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    cin>>Q;
    k = n/sqrt(Q);
    for (int i = 1; i <= Q; ++i) {
        cin>>q[i].ql>>q[i].qr;
        if (q[i].ql > q[i].qr) swap(q[i].ql,q[i].qr);
        q[i].id = i;
    }
    sort(q+1,q+Q+1);
    int l = 1, r = 0, pre = -1;
    for (int i = 1; i <= Q; ++i) {
        int cl = q[i].ql, cr = q[i].qr;
        if (cl/k == cr/k) {
            mx = -1e9-5;
            for (int i = cl; i <= cr; ++i) mx = max(mx,arr[i]);
        } else if (cl/k == pre) {
            l = (cl/k)*k+k;
            while(r < cr) cmax = max(arr[++r],cmax);
            mx = cmax;
            while(l > cl) mx = max(mx,arr[--l]);
        } else {
            l = (cl/k)*k+k, r = (cl/k)*k+k-1;
            pre = (cl/k)*k;
            cmax = mx = -1e9-5;
            while(r < cr) cmax = max(arr[++r],cmax);
            mx = cmax;
            while(l > cl) mx = max(mx,arr[--l]);
        }
        ans[q[i].id] = mx;
    }
    for (int i = 1; i <= Q; ++i) cout<<ans[i]<<endl;
    return 0;
}

