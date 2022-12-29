#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, n; cin>>x>>n;
    set<int> bdr;
    multiset<int> sz;
    bdr.insert(0), bdr.insert(x);
    sz.insert(x);
    for (int i = 0; i < n; ++i) {
        int p; cin>>p;
        auto r = bdr.upper_bound(p);
        auto l = --bdr.upper_bound(p);
        bdr.insert(p);
        sz.erase(sz.find(*r-*l));
        sz.insert(p-*l), sz.insert(*r-p);
        if (i) cout<<' ';
        cout<<*sz.rbegin();
    }
    
    return 0;
}
