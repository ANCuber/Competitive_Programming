#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Line{
    int a, b;
};

//dp[i] = min(f[j]*s[i]+dp[j]);

bool cmp(Line M, Line N, Line X) {
    return (X.a-N.a)*(M.b-N.b) >= (N.a-M.a)*(N.b-X.b);
}

bool del(Line M, Line N, int x) {
    return M.a*x+M.b >= N.a*x+N.b;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;
    vector<int> s(n+2), f(n+2), dp(n+2);
    deque<Line> dq;
    for (int i = 1; i <= n; ++i) cin>>s[i];
    for (int i = 1; i <= n; ++i) cin>>f[i];
    dp[0] = 0;
    dq.push_back({x,0});
    for (int i = 1; i <= n; ++i) {
        while(dq.size() > 1 && del(dq[0],dq[1],s[i])) {
            dq.pop_front();
        }
        dp[i] = s[i]*dq.front().a+dq.front().b;
        Line cur = {f[i],dp[i]};
        while(dq.size() > 1 && cmp(dq[dq.size()-2],dq.back(),cur)) {
            dq.pop_back();
        }
        dq.push_back(cur);
    }
    cout<<dp[n]<<endl;
    return 0;
}
