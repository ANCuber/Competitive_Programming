#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    bitset<32> bs[n+3];
    for (int i = 0; i < n; ++i) {
        string x; cin>>x;
        for (int j = 0; j < x.size(); ++j) {
            bs[i][j] = (x[j] == '1');
        }
    }
    bitset<32> tmp;
    int ans = k;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            tmp = bs[i]^bs[j];
            ans = min(ans,int(tmp.count()));
        }
    }
    cout<<ans<<endl;
    return 0;
}
