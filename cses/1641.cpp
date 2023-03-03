#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
int a[5005];
int n, x;
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>x;
    unordered_map< int,pii > mp;
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i <= n; ++i) {
        if (mp.count(x-a[i])) {
            cout<<mp[x-a[i]].first<<' '<<mp[x-a[i]].second<<' '<<i<<endl;
            return 0;
        }
        for (int j = 1; j < i; ++j) {
            if (a[i]+a[j] < x) mp[a[i]+a[j]] = {j,i};
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
