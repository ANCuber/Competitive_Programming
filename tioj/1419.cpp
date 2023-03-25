#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct DOT{
    int d, h;
    bool operator<(DOT b) {
        if (d == b.d) return h > b.h;
        return d < b.d;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<DOT> dot(n+1);
    for (int i = 0; i < n; ++i) {
        int x, y, h;
        cin>>x>>y>>h;
        dot[i] = {x*x+y*y,h};
    }
    sort(dot.begin(),dot.end());
    int mx = dot[0].h;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans,mx-dot[i].h);
        mx = max(mx,dot[i].h);
    }
    cout<<ans<<endl;
    return 0;
}
