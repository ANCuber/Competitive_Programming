#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int n, ql, qr;
ll ans = 0;

struct Rec{
    int v;
    ll y;
    int lx, rx;
    bool operator<(Rec b) {
        return y < b.y;
    }
};

struct Nd{
    int len = 0;
    int tag = 0;
};

vector<Rec> rec;
vector<Nd> seg(4000005);

void pull(int p, int d) {
    //cout<<d<<endl;
    if (seg[p].tag) seg[p].len = d;
    else seg[p].len = seg[p<<1].len+seg[p<<1|1].len;
}

void add(int l, int r, int p, int v) {
    if (ql <= l && r <= qr) {
        seg[p].tag += v;
        pull(p,r-l);
        return;
    }
    int mid = (l+r)>>1;
    if (qr <= mid) add(l,mid,p<<1,v);
    else if (ql >= mid) add(mid,r,p<<1|1,v);
    else {
        add(l,mid,p<<1,v);
        add(mid,r,p<<1|1,v);
    }
    pull(p,r-l);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    rec.resize(n<<1);
    int l, r, d, u;
    for (int i = 0; i < (n<<1); i += 2) {
        cin>>l>>r>>d>>u;
        rec[i].y = u;
        rec[i].v = -1;
        rec[i+1].y = d;
        rec[i+1].v = 1;
        rec[i].lx = rec[i+1].lx = l;
        rec[i].rx = rec[i+1].rx = r;
    }
    sort(rec.begin(),rec.end());
    for (int i = 0; i < (n<<1); i++) {
        //cout<<seg[1].len<<endl;
        if (i) ans += seg[1].len*(rec[i].y-rec[i-1].y);
        ql = rec[i].lx, qr = rec[i].rx;
        add(0,1000000,1,rec[i].v);
    }
    cout<<ans<<endl;
    return 0;
}
