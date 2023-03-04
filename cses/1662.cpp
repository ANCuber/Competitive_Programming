#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int sum = 0, ans = 0;
    vector<vector<int> > cnt(n,vector<int>(2,0));
    cnt[0][1] = 1;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        sum += a;
        if (sum >= 0) {
            ans += cnt[sum%n][1];
            ans += cnt[(n-sum%n)%n][0];
            cnt[sum%n][1]++;
        } else {
            ans += cnt[(-sum)%n][0];
            ans += cnt[(n-(-sum)%n)%n][1];
            cnt[(-sum)%n][0]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
