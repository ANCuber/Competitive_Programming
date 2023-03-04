#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct PAIR{
    int l, r, val;
    bool operator<(PAIR b) {
        return l < b.l;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    map< int,pii > mp;
    for (int i = 1;i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (mp.count(x-a[i]-a[j])) {
                cout<<mp[x-a[i]-a[j]].first<<' '<<mp[x-a[i]-a[j]].second<<' '<<i<<' '<<j<<endl;
                return 0;
            }
        }
        for (int j = 1; j < i; ++j) {
            if (a[i]+a[j] < x) mp[a[i]+a[j]] = {j,i};
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
