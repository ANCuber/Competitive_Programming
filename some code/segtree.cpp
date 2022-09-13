#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

const int MAXN = 5e5+5;

struct Seg{
    int sz;
    vector<int> a, tag;
    void init(int n) {
        sz = n;
        a.assign((n<<1)+5,0);
        tag.assign(n+5,0);
        for (int i = 0; i < n; ++i) cin>>a[i+n];
        for (int i = n-1; i > 0; --i) a[i] = max(a[i<<1],a[i<<1|1]);
    }
    void upd(int p, int x) {
        a[p] += x;
        if (p < sz) tag[p] += x;
    }
    void pull(int p) {
        while(p > 1) {
            a[p>>1] = max(a[p],a[p^1])+tag[p>>1];
            p >>= 1;
        }
    }
    void push(int p) {
        for (int h = __lg(sz); h >= 0; --h) {
            int i = p>>h;
            if (tag[i>>1]) {
                upd(i,tag[i>>1]);
                upd(i^1,tag[i>>1]);
                tag[i>>1] = 0;
            }
        }
    }
    void mdf(int l, int r, int x) {
        l+=sz,r+=sz;
        int tl = l, tr = r;
        push(l),push(r-1);
        for (; l < r; l>>=1, r>>=1) {
            if (l&1) upd(l++,x);
            if (r&1) upd(--r,x);
        }
        pull(tl),pull(tr-1);
    }
    int query(int l, int r) {//[l,r)
        int ret = INT_MIN;
        l+=sz,r+=sz;
        push(l),push(r-1);
        for (; l < r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret,a[l++]);
            if (r&1) ret = max(ret,a[--r]);
        }
        return ret;
    }
} seg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    seg.init(n);
    int cmd, a, b, x;
    while(q--) {
        cin>>cmd>>a>>b;
        a--;
        if (cmd == 1) {
            cin>>x;
            seg.mdf(a,b,x);
        } else {
            cout<<seg.query(a,b)<<endl;
        }
    }
    return 0;
}
