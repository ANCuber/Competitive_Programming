#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int t; cin>>t;
    while(t--) {
        int n, k, c;
        cin>>n>>k>>c;
        ll val[n];
        for (int i = 0; i < n; ++i) {
            cin>>val[i];
        }
        ll dp[n] = {0};
        dp[0] = val[0];
        deque <ll> t;
        t.push_back(0);
        for (int i = 1; i < n; ++i) {
            while(t.front() < i-k) t.pop_front();
            dp[i] = max(val[i]*1LL,dp[t.front()]+val[i]-1LL*c*(i-t.front()));
            while(!t.empty()) {
                if (dp[i]+1LL*c*i < dp[t.back()]+1LL*c*t.back()) break;
                t.pop_back();
            }
            t.push_back(i);
        }
        ll ans = -1e15;
        for (int i = 0; i < n; ++i) {
            ans = max(ans,dp[i]);
        }
        ans = max(ans,0LL);
        cout<<ans<<endl;
    }
}