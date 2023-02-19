#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct Segment{
    int l, r, w;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<Segment> arr(n);
    set<int> s;
    map<int,int> mp;
    for (auto& [l,r,w] : arr) {
        cin>>l>>r>>w;
        if (l > r) swap(l,r);
        s.insert(l), s.insert(r);
    }
    int cnt = 0;
    for (auto i : s) mp[i] = ++cnt;
    vector<int> pre(cnt+5,0), dp(cnt+5,0);
    for (auto [l,r,w] : arr) {
        pre[mp[l]] += w;
    }
    for (int i = 1; i < pre.size(); ++i) pre[i] += pre[i-1];
    dp[0] = max(0ll,pre[0]);
    for (int i = 1; i <= cnt; ++i) {
        int mx = 0;
        for (int j = 0; j < i; ++j) {
            mx = max(mx,dp[j]+pre[i]-pre[j]);
        }
        dp[i] = max(mx,pre[i]-pre[i-1]);
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}
