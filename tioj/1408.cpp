#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)
#define int ll

int n;

struct Rng{
    int a, b, c;
    bool operator<(Rng y) {
        if (b == y.b)  return a < y.b;
        return b < y.b;
    }
};

struct SEG {
    vector<int> a;
    vector<bool> tg;
    void init() {
        a.assign(100001<<2,0);
        tg.assign(100001<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] = c+1;
            if (c) {
                tg[p<<1] = 1;
                tg[p<<1|1] = 1;
            }
            tg[p] = 0;
        }
    }
    void upd(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] = 1;
            return;
        }
        if (qr <= mid) upd(l,mid,p<<1,ql,qr);
        else if (ql > mid) upd(mid+1,r,p<<1|1,ql,qr);
        else {
            upd(l,mid,p<<1,ql,qr);
            upd(mid+1,r,p<<1|1,ql,qr);
        }
        a[p] = (tg[p<<1]?(mid-l+1):a[p<<1])+(tg[p<<1|1]?(r-mid):a[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return (tg[p]?(r-l+1):a[p]);
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return query(l,mid,p<<1,ql,qr)+query(mid+1,r,p<<1|1,ql,qr);
    }
} seg;

void run() {
    if (!n) return;
    vector<Rng> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
        arr[i].a++;
    }
    sort(arr.begin(),arr.end());
    seg.init();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].a > arr[i].b) continue;
        int cur = arr[i].c-seg.query(1,100000,1,arr[i].a,arr[i].b);
        if (cur > 0) {
            int l = arr[i].a, r = arr[i].b+1;
            while(r-l > 1) {
                if (arr[i].b-mid+1-seg.query(1,100000,1,mid,arr[i].b) < cur) r = mid;
                else l = mid;
            }
            seg.upd(1,100000,1,l,arr[i].b);
            cnt += cur;
        }
    }
    printf("%d\n",cnt);
}

signed main() {
    while(true) {
        scanf("%d",&n);
        run();
        if (!n) break;
    }
    return 0;
}
