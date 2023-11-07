#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define endl '\n'

struct Query{
    int l, r, x;
};

void Run() {
    int n; cin>>n;
    vector<int> a(n+5), t(n+5,0);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    int Q; cin>>Q;
    vector<Query> q(Q+5);
    int mxid = 0;
    map<int,int> mp;
    for (int i = 1; i <= Q; ++i) {
        int l, r, x; 
        cin>>l>>r>>x;
        q[i] = {l,r,x};
        mp[l] += x;
        if (!mp[l]) mp.erase(l);
        mp[r+1] -= x;
        if (!mp[r+1]) mp.erase(r+1);
        auto iter = mp.begin();
        if (iter != mp.end() && iter->second < 0) {
            mxid = i;
            mp.clear();
        }
    }
    for (int i = 1; i <= mxid; ++i) {
        t[q[i].l] += q[i].x;
        t[q[i].r+1] -= q[i].x;
    }
    for (int i = 1; i <= n; ++i) t[i] += t[i-1];
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<a[i]+t[i];
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
