#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        sz = 1<<(__lg(_n)+1);
        a.assign(sz+2,0);
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int pos(int g) {
        int p = 0, s = 0;
        for (int i = __lg(sz); i >= 0; --i) {
            if (p+(1<<i) <= sz && a[p+(1<<i)]+s < g) {
                s += a[p+(1<<i)];
                p += (1<<i);
            }
        }
        return p+1;
    }
    int val(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit, sum;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    map<int,int> mp, rmp;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        s.insert(a[i]);
    }
    int c = 0;
    for (auto i : s) mp[i] = ++c;
    bit.init(c), sum.init(c);
    for (int i = 1; i <= n; ++i) {
        rmp[mp[a[i]]] = a[i];
        a[i] = mp[a[i]];
    }
    int all = 0;
    for (int i = 1; i <= k; ++i) {
        bit.add(a[i],1);
        sum.add(a[i],rmp[a[i]]);
        all += rmp[a[i]];
    }
    int tmp = bit.pos((k+1)/2);
    int cs = sum.val(tmp-1)+((k/2)-bit.val(tmp-1))*rmp[tmp];
    //cout<<all<<' '<<rmp[tmp]<<' '<<cs<<endl;
    cout<<(all-cs-rmp[tmp]*((k+1)/2))+(rmp[tmp]*(k/2)-cs);
    
    for (int i = k+1; i <= n; ++i) {
        bit.add(a[i],1);
        sum.add(a[i],rmp[a[i]]);
        all += rmp[a[i]];
        bit.add(a[i-k],-1);
        sum.add(a[i-k],-1*rmp[a[i-k]]);
        all -= rmp[a[i-k]];
        tmp = bit.pos((k+1)/2);
        cs = sum.val(tmp-1)+((k/2)-bit.val(tmp-1))*rmp[tmp];
        //cout<<' '<<all<<' '<<rmp[tmp]<<' '<<cs<<endl;
        cout<<' '<<(all-cs-rmp[tmp]*((k+1)/2))+(rmp[tmp]*(k/2)-cs);
    }
    cout<<endl;
    return 0;
}
