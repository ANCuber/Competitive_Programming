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
        a.assign(_n+5,0);
        sz = _n;
    }
    void chg(int p, int v) {
        while(p <= sz) {
            a[p] = max(a[p],v);
            p += p&-p;
        }
    }
    int mx(int p) {
        int ret = 0;
        while(p) {
            ret = max(ret,a[p]);
            p -= p&-p;
        }
        return ret;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n);
    set<int> s;
    for (auto& i : a) {
        cin>>i;
        s.insert(i);
    }
    map<int,int> mp;
    int c = 0;
    for (auto i : s) mp[i] = ++c;
    for (auto& i : a) i = mp[i];
    bit.init(c);
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        cout<<bit.mx(a[i]-1);
        bit.chg(a[i],i+1);
    }
    cout<<endl;
    return 0;
}
