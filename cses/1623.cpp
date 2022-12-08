#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    int sum = 0, ans = 1e18;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        sum += a[i];
    }
    for (int i = 0; i < (1<<n); ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if ((i>>j)&1) cur += a[j];
        }
        ans = min(ans,abs(sum-2*cur));
    }
    cout<<ans<<endl;
    return 0;
}
