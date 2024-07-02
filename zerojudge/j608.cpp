#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Interval{
    int L, R;
    bool operator<(Interval y) {
        return R < y.R;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector<Interval> a(n+2); 
    set<int> s;
    map<int,int> mp;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i].L;
        s.insert(a[i].L);
    }
    for (int i = 1; i <= n; ++i) {
        cin>>a[i].R;
        s.insert(a[i].R);
    }
    int c = 0;
    for (auto i : s) mp[i] = ++c;
    for (int i = 1; i <= n; ++i) {a[i].L = mp[a[i].L], a[i].R = mp[a[i].R]};
    sort(a.begin()+1,a.begin()+n+1);
    
    
    
    return 0;
}
