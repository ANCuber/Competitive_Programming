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
    int n;
    while(cin>>n) {
        int s = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            mx = max(mx,x);
            s += x;
        }
        if (2*mx >= s) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
