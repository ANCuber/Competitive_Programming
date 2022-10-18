#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, w;

bool slv(int g, vector<int> &s) {
    vector<int> dp(n+1);
    dp[0] = -1;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while(!q.empty() && s[i]-s[q.front()] > g) q.pop_front();
        if (q.empty()) {
            return 0;
        } else {
            dp[i] = dp[q.front()]+1;
        }
        while(!q.empty() && dp[i] <= dp[q.back()]) q.pop_back();
        q.push_back(i);
    }
    return dp[n] <= w;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>w && (n+w)) {
        vector<int> s(n+1,0);
        for (int i = 1; i <= n; ++i) {
            cin>>s[i];
            s[i] += s[i-1];
        }
        int l = 0, r = s[n];
        int mid = (l+r)>>1;
        while(r-l>1) {
            if (slv(mid,s)) r = mid;
            else l = mid;
            mid = (l+r)>>1;
        }
        cout<<r<<endl;
    }
    return 0;
}
