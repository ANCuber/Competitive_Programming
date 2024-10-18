#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    string s; cin>>s;
    s = "*"+s;
    vector<int> cnt(n+5,0);
    for (int i = 2; i < n; ++i) {
        if (s[i-1] == '4' && s[i] == '9') {
            cnt[i]++;
        }
        cnt[i] += cnt[i-1];
    }
    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        int cur = cnt[r]-cnt[l];
        if (cur == (r-l+1)/2 && (r+l)%2 == 0) {
            cout<<"-1\n";
        } else {
            cout<<"2 "<<
        }
    }
    return 0;
}
