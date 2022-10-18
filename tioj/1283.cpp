#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define pf push_front

struct dot {
    ll x, y;
};

struct rng{
    int l, r, id;
};


inline ll area(dot d1, dot d2) {
    return (d1.x-d2.x)*(d2.y-d1.y);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n; 
    n >>= 1;
    vector<dot> a(n+1);
    ll x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        ll dx, dy; cin>>dx>>dy;
        x += dx;
        a[i].x = x;
        a[i].y = y;
        y += dy;
    }
    int m; cin>>m;
    m >>= 1;
    vector<dot> b(m+1);
    x = 0, y = 0;
    for (int i = 1; i <= m; ++i) {
        ll dx, dy; cin>>dy>>dx;
        y += dy;
        b[i].x = x;
        b[i].y = y;
        x += dx;
    }

    deque<rng> q;
    q.pb({1,m,1});
    for (int i = 2; i <= n; ++i) {
        while(!q.empty() && area(a[i],b[q.back().l]) >= area(a[q.back().id],b[q.back().l])) {
            q.pop_back();
        }
        if (q.empty()) {
            q.pb({1,m,i});
        } else {
            rng tmp = q.back();
            q.pop_back();
            int l = tmp.l, r = tmp.r+1;
            int mid = (l+r)>>1;
            while(r-l>1) {
                if (area(a[i],b[mid]) >= area(a[tmp.id],b[mid])) r = mid;
                else l = mid;
                mid = (l+r)>>1;
            }
            q.pb({tmp.l,r-1,tmp.id});
            if (r <= m) q.pb({r,m,i});
        }
    }

    ll ans = 0;
    for (auto i : q) {
        //cerr<<i.l<<' '<<i.r<<' '<<i.id<<endl;
        for (int j = i.l; j <= i.r; ++j) {
            ans = max(ans,area(a[i.id],b[j]));
        }
    }
    cout<<ans<<endl;    
    
    return 0;
}
