#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, n; cin>>r>>c>>n;
    int cnt = 0, dis = 0;
    vector<int> h(r+2,0);
    while(n--) {
        char t;
        int y, mx = -1;
        cin>>t>>y;
        if (t == 'A') {
            for (int i = 0; i < 4; ++i) mx = max(mx,h[y+i]);
            if (mx < c) {
                for (int i = 0; i < 4; ++i) h[y+i] = mx+1;
                cnt += 4;
            } else dis++;
        } else if (t == 'B') {
            if (h[y]+3 <= c) {
                h[y] += 3;
                cnt += 3;
            } else dis++;
        } else if (t == 'C') {
            mx = max(h[y],h[y+1]);
            if (mx+2 <= c) {
                h[y] = h[y+1] = mx+2;
                cnt += 4;
            } else dis++;
        } else if (t == 'D') {
            mx = max(h[y]+1,h[y+1]+3);
            if (mx <= c) {
                h[y] = h[y+1] = mx;
                cnt += 4;
            } else dis++;
        } else if (t == 'E') {
            mx = max({h[y]+1,h[y+1]+2,h[y+2]+2});
            if (mx <= c) {
                h[y] = h[y+1] = h[y+2] = mx;
                cnt += 5;
            } else dis++;
        }
    }
    cout<<r*c-cnt<<' '<<dis<<'\n';
    return 0;
}
