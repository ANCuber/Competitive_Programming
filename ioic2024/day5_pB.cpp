#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

int N, K;
vector<int> a;

struct BIT{
    vector<ll> v;
    int sz;
    void init(int _n) {
        sz = _n;
        v.assign(_n+5,0);
    }
    void mdf(int p, ll x) {
        while(p <= sz) {
            v[p] += x;
            p += p&-p;
            //cout<<p<<endl;
        }
    }
    ll query(int p) {
        ll ret = 0;
        while(p) {
            ret += v[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;    
    bit.init(N+5);
    a.resize(N+5);
    for (int i = 1; i <= N; ++i) cin>>a[i];
    int cnt = 0, ans = 0;
    map<int,int> mp;
    vector<int> tmp, r(N+2,0);
    tmp.pb(0);
    for (int i = 1; i <= N; ++i) {
        r[a[i]]++;
        if (mp.count(a[i])) {
            tmp.pb(mp[a[i]]);
        } else {
            mp[a[i]] = ++cnt;
            tmp.pb(0);
        }
    }
    for (int i = 1;i <= K; ++i) {
        if (r[i] == 1) {
            tmp.pb(mp[i]);
        }
    }
    sort(tmp.begin()+N+1,tmp.end());

    //for (int i = 1; i <= 2*K; ++i) cout<<tmp[i]<<' '; cout<<endl;
    
    for (int i = 1; i < tmp.size(); ++i) {
        ans += bit.query(N)-bit.query(tmp[i]);
        if (tmp[i]) bit.mdf(tmp[i],1);
    }
    cout<<ans<<endl;
    return 0;
}
