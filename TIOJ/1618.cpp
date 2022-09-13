#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector<int> h(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) cin>>h[i];
    for (int i = 1; i <= n; ++i) cin>>b[i];
    deque<int> dq;
    pii ans = {1,b[1]};
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        while(!dq.empty() && dq.front() <= i-k) {
            sum -= b[dq.front()];
            dq.pop_front();
        }
        while(!dq.empty() && h[dq.back()] <= h[i]) {
            sum -= b[dq.back()];
            dq.pop_back();
        }
        sum += b[i];
        dq.push_back(i);
        if (ans.second < sum) {
            ans.first = i;
            ans.second = sum;
        }
        //cout<<"view"<<i<<':'<<sum<<endl;
    }
    cout<<ans.first<<' '<<ans.second<<endl;
    
    return 0;
}
