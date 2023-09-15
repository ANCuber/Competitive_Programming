#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    cin>>n;    
    p_q <int,vector<int>,greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x;
        pq.push(x);
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a+b);
        pq.push(a+b);
    }
    cout<<ans<<'\n';
    return 0;
}

