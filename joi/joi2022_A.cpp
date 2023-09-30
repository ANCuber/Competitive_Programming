#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n);
    deque<int> ans, ps;
    for (auto& i : a) cin>>i;
    
    while(!a.empty()) {
        int cur = a.back(), cnt = 1;
        a.pop_back();
        while(cur&1^1) {
            cur >>= 1;
            cnt <<= 1;
        }
        ans.push_front(cur);
        ps.push_front(cnt);
    }
    //for (int i = 0; i < ps.size(); ++i) cout<<ans[i]<<' '<<ps[i]<<endl;
    for (int i = 1; i < ps.size(); ++i) ps[i] += ps[i-1];
    
    int q; cin>>q;
    while(q--) {
        int x; cin>>x;
        int l = -1, r = ps.size()+1;
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if (ps[mid] < x) l = mid;
            else r = mid;
        }
        //cout<<ps[l]<<' '<<ps[r]<<endl;
        cout<<ans[r]<<endl;
    }
    return 0;
}
