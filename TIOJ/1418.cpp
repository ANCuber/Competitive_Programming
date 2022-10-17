#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

int cnt(int x) {
    int ans = 0;
    while(x) {
        x -= (x&-x);
        ans++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<int> > r(n+1,vector<int>(n+1,0));
        vector<int> dp(1<<n,1e9);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin>>r[i][j];
            }
        }
        
        for (int i = 0; i < (1<<n); ++i) {
            if (cnt(i)%3 == 0) {
                
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    
    return 0;
}
