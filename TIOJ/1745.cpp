#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ll a, b, c;
    cin>>a>>b>>c;
    vector<ll> x(n+1);
    vector<ll> s(n+1,0);
    vector<ll> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>x[i];
        s[i] = s[i-1]+x[i];
    }
    deque<pair<ll,ll> > q;//(s[x],f(x));
    q.push_back({0,0});
    
    for (int i = 1; i <= n; ++i) {
        ll m = a*s[i]*s[i]+b*s[i]+c;
        pair<ll,ll> qf, qs;
        while(q.size()>1) {
            qf = q.front();
            q.pop_front();
            qs = q.front();
            if (!(s[i]*qs.first+qs.second > s[i]*qf.first+qf.second)) {
                q.push_front(qf);
                break;
            }
        }
        qf = q.front();
        dp[i] = qf.second+s[i]*qf.first+m;
        ll cur = dp[i]-b*s[i]+a*s[i]*s[i];
        while(q.size()>1) {
            qf = q.back();
            q.pop_back();
            qs = q.back();
            if (!((qs.second-cur)*(qf.first-qs.first) <= (qf.second-qs.second)*(qs.first+2*a*s[i]))) {
                q.push_back(qf);
                break;
            }
        }
        q.push_back({-2*a*s[i],cur});
    }
    cout<<dp[n]<<endl;

    return 0; 
}
