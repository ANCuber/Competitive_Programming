#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n, k;

bool check(vector<int> &p, int g) {
    int pre = p[0], cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (p[i]-pre > g) {
            cnt++;
            pre = p[i];
        }
    }
    return cnt <= k;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    vector<int> p(n);
    for (auto &i : p) cin>>i;
    sort(p.begin(),p.end());
    int l = -1, r = 1e9+5, mid;
    while(r-l > 1) {
        mid = (l+r)>>1;
        if (check(p,mid)) r = mid;
        else l = mid;
    }
    cout<<r<<'\n';
    return 0;
}
