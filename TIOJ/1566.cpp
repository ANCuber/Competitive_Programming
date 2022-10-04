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
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> h(n+1);
    deque<int> mx, mn;
    for (int i = 1; i <= n; ++i) cin>>h[i];
    mx.pb(1), mn.pb(1);
    int cnt = 0;
    vector< pii > ans;
    for (int i = 2; i <= n; ++i) {
        while(!mx.empty() && i-mx.front() >= m) mx.pop_front();
        while(!mn.empty() && i-mn.front() >= m) mn.pop_front();
        while(!mx.empty() && h[i] >= h[mx.back()]) mx.pop_back();
        while(!mn.empty() && h[i] <= h[mn.back()]) mn.pop_back();
        mx.pb(i), mn.pb(i);
        
        if (h[mx.front()]-h[mn.front()] == k) {
            cnt++;
            ans.pb({max(1LL,i-m+1),i});
        }
    }
    for (int i = n-m+2; i <= n-1; ++i) {
        while(!mx.empty() && mx.front() < i) mx.pop_front();
        while(!mn.empty() && mn.front() < i) mn.pop_front();
        if (h[mx.front()]-h[mn.front()] == k) {
            cnt++;
            ans.pb({max(1LL,i),n});
        }
    }
    cout<<cnt<<endl;
    for (auto i : ans) cout<<i.first<<' '<<i.second<<endl;
    
    return 0; 
}
