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
    int L, N; cin>>L>>N;    
    vector<int> a(N);
    for (auto& i : a) cin>>i;
    sort(a.begin(),a.end());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (!i) {
            if (a[i]%15 == 0) ans += a[i]/15-1;
            else ans += a[i]/15;
        } else {
            int tmp = (a[i]-a[i-1]);
            if (tmp%15 == 0) {
                ans += tmp/15-1;
            } else {
                ans += tmp/15;
            }
        }
        //cout<<ans<<' '<<endl;
    }
    if (L >= a[N-1]+15) ans += (L-a[N-1])/15;
    cout<<ans<<endl;
    return 0;
}
