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
    for (int i = 1; i <= n; ++i) {
        ans += (n%i);
    }
    cout<<ans<<endl;
    return 0;
}
