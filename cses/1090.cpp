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
    int n, x; cin>>n>>x;
    vector<int> p(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    p.pb(1e9+5);
    int cnt = 0, res = 0, p = 0, ud = n;
    while(ud) {
        int l = 0, r = n+1;
        int mid = (l+r)>>1;
        while(r-l > 1) {
            if (p[mid] <= res) l = mid;
            else r = mid;
            mid = (l+r)>>1;
        }
        
        
    }
    cout<<cnt<<endl;
    return 0;
}
