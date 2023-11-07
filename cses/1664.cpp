#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Range{
    int L, R;
    bool operator<(Range y) {
        return R < y.R;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<Range> a(n);
    vector<int> mn(n+5,0), id(n+5);
    vector<vector<int> > bz(__lg(n)+5,vector<int>(n+5,0));
    for (auto& [i,j] : a) cin>>i>>j;
    sort(a.begin(),a.end());
    for (int i = 0; i < n; ++i) {
        
    }
    for (int i = 0; i < n; ++i) {
        
    }

    while(q--) {
        int x, y; cin>>x>>y;
        
    }
    return 0;
}
