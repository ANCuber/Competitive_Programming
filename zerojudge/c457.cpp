#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

int n, k;

struct alien{
    int mx, cnt;
};

alien amax(alien a, alien b) {
    if (a.mx == b.mx) {
        if (a.cnt>b.cnt) return b;
        else return a;
    } else {
        if (a.mx>b.mx) return a;
        else return b;
    }
}

alien cal(int p, vector<int> &prc) {
    alien dp0 = {0,0}, dp1 = {-prc[1],0};
    for (int i = 2; i <= n; ++i) {
        alien cur = dp0;
        dp0 = amax(dp0,{dp1.mx+prc[i]-p,dp1.cnt+1});
        dp1 = amax(dp1,{cur.mx-prc[i],cur.cnt});
    }
    return dp0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<int> prc(n+1,0);
    for (int i = 1; i <= n; ++i) cin>>prc[i];
    int l = -1, r = 1e7;
    int mid = (l+r)>>1;
    while(r-l>1) {
        if (cal(mid,prc).cnt > k) l = mid;
        else r = mid;
        mid = (l+r)>>1;
    }
    cout<<cal(r,prc).mx+k*r<<endl;
    
    return 0;
}

