#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int arr[200005];

struct SEG {
    vector<int> a, pos;
    int sz;
    void setup(int l, int r, int p) {
        if (l == r) {
            a[p] = arr[l];
            pos[p] = l;
            return;
        }
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1);
        if (a[p<<1] > a[p<<1|1]) {
            a[p] = a[p<<1|1];
            pos[p] = pos[p<<1|1];
        } else {
            a[p] = a[p<<1];
            pos[p] = pos[p<<1];
        }
    }
    void init(int _n) {
        sz = _n;
        a.assign(_n<<2,0);
        pos.assign(_n<<2,0);
        setup(1,_n,1);
    }
    void upd(int l, int r, int p, int tar, int v) {
        if (l == r) {
            a[p] = v;
            pos[p] = l;
            return;
        }
        if (tar <= mid) upd(l,mid,p<<1,tar,v);
        else upd(mid+1,r,p<<1|1,tar,v);
        if (a[p<<1] > a[p<<1|1]) {
            a[p] = a[p<<1|1];
            pos[p] = pos[p<<1|1];
        } else {
            a[p] = a[p<<1];
            pos[p] = pos[p<<1];
        }
    }
    pii query(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return {a[p],pos[p]};
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else {
            pii lc = query(l,mid,p<<1,ql,qr), rc = query(mid+1,r,p<<1|1,ql,qr);
            if (lc.first > rc.first) return rc;
            else return lc;
        }
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    int n, k;
    while(t--) {
        cin>>n>>k;
        for (int i = 1; i <= n; ++i) cin>>arr[i];
        int l = 1;
        for (int i = 1; i <= n-k+1; ++i) {
            int mx = arr[i];
            for (int j = i; j <= i+k-1; ++j) {
                if (arr[j] < mx) {
                    int lll = i-1, rrr = j-1;
                    int m = (lll+rrr)>>1;
                    while(rrr-lll > 1) {
                        if (arr[m] < arr[j]) lll= m;
                        else rrr = m;
                        m = (lll+rrr)>>1;
                    }
                    swap(arr[j],arr[rrr]);
                    break;
                }
                mx = arr[j];
            }
        }
        /*seg.init(n);
        for (int i = 1; i <= n-k+1; ++i) {
            pii q = seg.query(1,n,1,i,i+k-1);
            if (q.first == arr[i]) {
                pii q3 = seg.query(1,n,1,i+1,i+k-1);
                int cnt = 1;
                while(q3.first == arr[i+cnt] && ++cnt < k) {
                    q3 = seg.query(1,n,1,i+cnt,i+k-1);
                }
                swap(arr[i+cnt],arr[q3.second]);
                seg.upd(1,n,1,i+1,0);
                seg.upd(1,n,1,q3.second,arr[q3.second]);
                seg.upd(1,n,1,i+1,arr[i+1]);
            } else {
                swap(arr[i],arr[q.second]);
                seg.upd(1,n,1,i,0);
                seg.upd(1,n,1,q.second,arr[q.second]);
                seg.upd(1,n,1,i,arr[i]);
            }
        }*/
        for (int i = 1; i <= n; ++i) {
            if (i != 1) cout<<' ';
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
