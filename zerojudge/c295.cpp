#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    int sum = 0;
    vector<int> arr(n), ans;
    for (int i = 0; i < n; ++i) {
        int mx = 0, x;
        for (int j = 0; j < m; ++j) {
            cin>>x;
            mx = max(mx,x);
        }
        arr[i] = mx;
        sum += mx;
    }
    for (auto i : arr) if (sum%i == 0) ans.push_back(i);
    cout<<sum<<'\n';
    if (ans.empty()) cout<<-1<<'\n';
    else {
        for (int i = 0; i < ans.size(); ++i) {
            if (i) cout<<' ';
            cout<<ans[i];
        }
        cout<<'\n';
    }
    return 0;
}
