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
    int n; cin>>n;    
    vector<vector<int> > p(n+1,vector<int>(n+1));
    vector<int> dp((1<<n)+5,-1e9);
    dp[0] = 100;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>p[i][j];
            p[i][j] *= 100;
        }
    }
    
    return 0;
}
