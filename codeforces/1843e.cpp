#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, q;

bool check(int g, vector<int> &a, vector<pii> &M) {
    vector<int> v(n+5,0);
    for (int i = 1; i <= n; ++i) {
        v[i] = v[i-1]+(a[i] <= g);
    }
    for (auto [l,r] : M) {
        if (v[r]-v[l-1] > (r-l+1)/2) return 1;
    }
    return 0;
}

void Run() {
    cin>>n>>m;
    vector<pii> M(m);
    vector<int> a(n+5,1e9);
    for (auto& [l,r] : M) cin>>l>>r;
    cin>>q;
    for (int i = 1; i <= q; ++i) {
        int c; cin>>c;
        a[c] = i;
    }
    int l = 0, r = q+1;
    while(r-l > 1) {
        int mid = (l+r)>>1;
        if (check(mid,a,M)) r = mid;
        else l = mid;
    }
    if (r == q+1) cout<<-1<<endl;
    else cout<<r<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
