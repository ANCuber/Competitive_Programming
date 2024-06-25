#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<int> p(n+1,0), q(m);//remember to minus 1
    for (int i = 1; i <= n; ++i) {
        cin>>p[i];
        p[i] += p[i-1];
    }
    for (auto &i : q) cin>>i;
    int cur = 1;
    for (auto &i : q) {
        int l, r, mid;
        if (p[n]-p[cur-1] < i) {
            l = 0, r = n+1;
            i -= (p[n]-p[cur-1]);
            while(r-l > 1) {
                mid = (l+r)>>1;
                if (p[mid] >= i) r = mid;
                else l = mid;
            }
        } else {
            l = cur-1, r = n+1;
            while(r-l > 1) {
                mid = (l+r)>>1;
                if (p[mid]-p[cur-1] >= i) r = mid;
                else l = mid;
            }
        }
        cur = r+1;
        if (cur > n) cur -= n;
    }
    cout<<(cur-1)<<'\n';
    return 0;
}
