#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

int k;

void solve(vector<int> &p, int l, int r, int dep, vector<int> &cut) {
    if (r-l+1 < 3 || dep > k) return;
    int sml = p[l]-p[l-1], smr = 0, mn = 0, id = 0;
    for (int i = l+2; i <= r; ++i) smr += (p[i]-p[i-1])*(i-l-1);
    mn = abs(sml-smr), id = l+1;
    for (int i = l+2; i < r; ++i) {
        sml += (p[i-1]-p[l-1]);
        smr -= (p[r]-p[i-1]);
        if (abs(sml-smr) < mn) {
            mn = abs(sml-smr);
            id = i;
        }
    }
    cut[id] = 1;
    solve(p,l,id-1,dep+1,cut), solve(p,id+1,r,dep+1,cut);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n>>k;
    vector<int> p(n+2), cut(n+2,0);
    for (int i = 1; i <= n; ++i) {
        cin>>p[i];
        p[i] += p[i-1];
    }
    solve(p,1,n,1,cut);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += cut[i]*(p[i]-p[i-1]);
    cout<<ans<<'\n';
    return 0;
}
