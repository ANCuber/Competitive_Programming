#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for (auto &i : a) cin>>i;
    for (int i = 0; i < n; ++i) {
        int b; cin>>b;
        a[i] = b-a[i];
        if (a[i] < 0) a[i] += 9;
    }
    int ans = 0;
    for (int i = 0; i <= n-k; ++i) {
        if (!a[i]) continue;
        int tmp = a[i];
        ans += tmp;
        for (int j = i; j < i+k; ++j) {
            a[j] -= tmp;
            if (a[j] < 0) a[j] += 9;
        }
    }
    if (*max_element(a.begin(),a.end()) > 0) cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}
