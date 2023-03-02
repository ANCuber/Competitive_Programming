#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t; cin>>n>>t;    
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    int l = 0, r = 1e18+1;
    int mid = l+(r-l)/2;
    
    while(r-l > 1) {
        int cnt = 0;
        for (auto i : a) {
            cnt += mid/i;
            if (cnt >= t) break;
        }
        if (cnt >= t) r = mid;
        else l = mid;
        mid = l+(r-l)/2;
    }
    cout<<r<<endl;
    return 0;
}
