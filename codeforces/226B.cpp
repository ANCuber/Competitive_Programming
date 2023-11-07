#pragma GCC optimize("Ofast","unroll-loops")
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
    vector<int> a(n+1,0), ans(100005,0);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    for (int i = 1; i <= n; ++i) a[i] += a[i-1];
    int q; cin>>q;
    for (int i = 0; i < q; ++i) {
        if (i) cout<<' ';
        int k; cin>>k;
        int L = max(1ll,n-k), R = n-1, cnt = 1;
        int ans = 0;
        do {
            ans += (a[R]-a[L-1])*cnt;
            cnt++;
            k *= k;
            R = L-1;
            L = max(1ll,R-k+1);
        } while(R >= L);
        cout<<ans;
    }
    cout<<endl;
    return 0;
}

