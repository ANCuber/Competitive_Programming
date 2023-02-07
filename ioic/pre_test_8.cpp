#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define pf push_front
#define int ll

struct ln {
    int a, b;
};

bool cmp(ln m, ln n, int k) {
    return m.a*k+m.b >= n.a*k+n.b;
}

bool check(ln m, ln n, ln k) {
    return (k.a-n.a)*(m.b-k.b) >= (k.a-m.a)*(n.b-k.b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, c; cin>>n>>c;    
    vector<int> h(n+1,0), dp(n+1);
    for (int i = 1; i <= n; ++i) cin>>h[i];
    dp[0] = dp[1] = 0;
    deque<ln> dq;
    dq.pb({-2*h[1],h[1]*h[1]});
    for (int i = 2; i <= n; ++i) {
        while(dq.size() > 1 && cmp(dq[0],dq[1],h[i])) dq.pop_front();
        dp[i] = h[i]*dq[0].a+dq[0].b+h[i]*h[i]+c;
        ln cur = {-2*h[i],h[i]*h[i]+dp[i]};
        while(dq.size() > 1 && check(dq[dq.size()-2],dq[dq.size()-1],cur)) dq.pop_back();
        dq.pb(cur);
    }
    cout<<dp[n]<<endl;
    return 0;
}
