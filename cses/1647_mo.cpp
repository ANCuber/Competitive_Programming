#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
int n, k, Q;
int mn = 1e9+5, cmin = 1e9+5;
int arr[200005];
int ans[200005];
 
struct Query{
    int ql, qr, id;
    bool operator<(Query b) {
        if (ql/k == b.ql/k) return qr < b.qr;
        return ql/k < b.ql/k;
    }
} q[200005];
 
signed main() {
    scanf("%d%d",&n,&Q);
    k = n/sqrt(Q);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    for (int i = 1; i <= Q; ++i) {
        scanf("%d%d",&q[i].ql,&q[i].qr);
        q[i].id = i;
    }
    sort(q+1,q+Q+1);
    int l = 1, r = 0, pre = -1;
    for (int i = 1; i <= Q; ++i) {
        int cl = q[i].ql, cr = q[i].qr;
        if (cl/k == cr/k) {
            mn = 1e9+5;
            for (int j = cl; j <= cr; ++j) mn = min(mn,arr[j]);
        } else if (cl/k == pre) {
            l = (cl/k)*k+k;
            while(r < cr) cmin = min(arr[++r],cmin);
            mn = cmin;
            while(l > cl) mn = min(mn,arr[--l]);
        } else {
            l = (cl/k)*k+k, r = (cl/k)*k+k-1;
            pre = (cl/k);
            cmin = mn = 1e9+5;
            while(r < cr) cmin = min(arr[++r],cmin);
            mn = cmin;
            while(l > cl) mn = min(mn,arr[--l]);
        }
        ans[q[i].id] = mn;
    }
    for (int i = 1; i <= Q; ++i) printf("%d\n",ans[i]);
    return 0;
}
