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
    int t, n;
    while(cin>>t>>n) {
        vector<int> f(n), d(n);
        p_q <int,vector<int>, greater<int> > pq;
        for (int i = 0; i < n; ++i) cin>>f[i];
        for (int i = 0; i < n; ++i) cin>>d[i];
        
        int ans = 0, cur = 0, flag = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin>>a;
            if (flag) continue;
            t -= a;
            while(t < 0 && !pq.empty()) {
                cur -= pq.top();
                pq.pop();
                t++;
            }
            if (t < 0 || (!t && pq.empty())) {
                flag = 1;
                continue;
            }
            for (int j = 0; f[i]-j*d[i] > 0; ++j) {
                if (t > 0) {
                    pq.push(f[i]-j*d[i]);
                    cur += f[i]-j*d[i];
                    t--;
                } else if (t == 0 && f[i]-j*d[i] > pq.top()) {
                    cur -= pq.top();
                    pq.pop();
                    pq.push(f[i]-j*d[i]);
                    cur += (f[i]-j*d[i]);
                } else {
                    break;
                }
            }
            ans = max(ans,cur);
        }
        cout<<ans<<endl;
    }
    return 0;
}
