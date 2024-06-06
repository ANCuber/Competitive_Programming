#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        int l, r; cin>>l>>r;
        ll bs = 1, cnt = 0;
        while(bs <= r) {
            bs <<= 1;
            cnt++;
        }
        cout<<cnt-1<<'\n';
    }
    return 0;
}
