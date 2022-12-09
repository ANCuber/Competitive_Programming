#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Range {
    int l, r;
    bool operator<(Range b) {
        if (r == b.r) l < b.l;
        return r < b.r;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<Range> v(n);
    for (int i = 0; i < n; ++i) cin>>v[i].l>>v[i].r;
    sort(v.begin(),v.end());
    int p = 0, cnt = 0;
    for (auto [l,r] : v) {
        if (l >= p) {
            cnt++;
            p = r;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
