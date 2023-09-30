#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(1000005,0);
    while(n--) {
        int x; cin>>x;
        a[x]++;
    }
    int ans = 1;
    for (int i = 1; i <= 1e6; ++i) {
        int cnt = 0;
        for (int j = i; j <= 1e6; j += i) cnt += a[j];
        if (cnt >= 2) ans = i;
    }
    cout<<ans<<endl;
    return 0;
}
