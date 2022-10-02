#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define pf push_front
#define fr first
#define sd second
#define int long long

int n, k;

struct line{
    int a, b, id;
};

bool cmp(line s, line t, int v) {
    return s.a*v+s.b <= t.a*v+t.b;
}

bool nw(line x, line y, line z) {
    return min(x.id+k,(x.b-y.b)/(y.a-x.a)) > (y.b-z.b)/(z.a-y.a);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<int> c(n+2,0), dp(n+2,0);
    deque<line> q;
    for (int i = n; i > 0; --i) cin>>c[i];
    for (int i = 1; i <= n; ++i) c[i] += c[i-1];
    q.pb({0,0,0});
    for (int i = 1; i <= n; ++i) {
        if(!q.empty() && i-k > q.front().id) q.pop_front();
        while(q.size()>=2 && cmp(q[0],q[1],i)) q.pop_front();
        dp[i] = q[0].a*i+q[0].b-i*i;
        line cur = {2*i,-i*i+c[i]+dp[i],i};
        while(q.size()>=2 && nw(q[q.size()-2],q.back(),cur)) q.pop_back();
        q.pb(cur);
    }
    cout<<dp[n]<<endl;
    return 0;
}
