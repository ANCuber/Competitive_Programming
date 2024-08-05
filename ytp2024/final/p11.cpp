#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Query{
    int cmd;
    int id, x, y;
    int a, b;
    int k;
};

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void mdf(int p, int x) {
        while(p <= sz) {
            a[p] = max(a[p],x);
            p += p&-p;
        }
    }
    int qq(int p) {
        int ret = 0;
        while(p) {
            ret = max(a[p],ret);
            p -= p&-p;
        }
        return ret;
    }
} bit;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin>>n>>q;
    vector<Query> op(q);
    set<int> s;
    for (int i = 0; i < q; ++i) {
        int cmd; cin>>cmd;
        op[i].cmd = cmd;
        if (cmd == 1) {
            cin>>op[i].id>>op[i].x>>op[i].y;
            s.insert(op[i].x);
        } else if (cmd == 2) {
            cin>>op[i].a>>op[i].b;
        } else {
            cin>>op[i].id>>op[i].k;
            s.insert(op[i].k);
        }
    }
    int c = 0;
    map<int,int> mp;
    for (auto i : s) mp[i] = ++c;
    bit.init(c);
    for (int i = 0; i < q; ++i) {
        if (op[i].cmd == 1) op[i].x = mp[op[i].x];
        if (op[i].cmd == 3) op[i].k = mp[op[i].k];
    }
    int flg = 0;
    for (int i = 0; i < q; ++i) {
        if (op[i].cmd == 1) {
            //cout<<op[i].x<<' '<<mp[op[i].x]<<'\n'; continue;

            flg = 1;
            bit.mdf(op[i].x,op[i].y);
        } else if (op[i].cmd == 3) {
            //cout<<op[i].k<<' '<<mp[op[i].k]<<'\n'; continue;
            if (!flg) cout<<-1<<'\n';
            else cout<<bit.qq(op[i].k)<<'\n';
        }
    }
    return 0;
}
