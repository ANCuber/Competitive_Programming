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
    int ans = 0;
    vector<int> a(n), b(n);
    for (auto& i : a) cin>>i;
    for (auto& i : b) cin>>i;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout<<-1<<endl;
            return 0;
        }
        ans += b[i]-a[i];
    }
    cout<<ans<<endl;
    return 0;
}
