#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#define pll pair<ll,ll>
#define double long double

vector< pii > g;

double dis(pii a, pii b) {
    double x1 = a.first-b.first;
    double y1 = a.second-b.second;
    return sqrt(x1*x1+y1*y1);
}

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

double DQ(int l, int r) {
    if (l == r) return 5e18;
    /*if (r-l == 1) {
        if (g[l].second > g[r].second) swap(g[l],g[r]);
        return dis(g[l],g[r]);
    }*/
    int mid = (r+l)>>1;
    int mdid = g[mid].first;
    double d = min(DQ(l,mid),DQ(mid+1,r));
    inplace_merge(g.begin()+l,g.begin()+mid+1,g.begin()+r+1,cmp);
    vector < pii > v;
    for (int i = l; i <= r; ++i) {
        if (abs(g[i].first - mdid) <= d) {
            v.push_back(g[i]);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            d = min(d,dis(v[i],v[j]));
            if (abs(v[i].second-v[j].second) > d) break;
        }
    }
    return d;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        g.resize(n);
        for (int i = 0; i < n; ++i) cin>>g[i].first>>g[i].second;
        sort(g.begin(),g.end());
        double ans = DQ(0,n-1);
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}
