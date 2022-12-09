#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;    
    vector<int> a(n+1);
    set< pii > s;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        s.insert({a[i],i});
    }
    for (int i = 1; i <= n; ++i) {
        auto iter = s.lower_bound({x-a[i],0});
        if (iter == s.end()) continue;
        if (iter->first == x-a[i] && iter->second != i) {
            cout<<min(i,iter->second)<<' '<<max(i,iter->second)<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
