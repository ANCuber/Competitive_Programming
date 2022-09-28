#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

int n, m;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;        
    while(t--) {
        cin>>n>>m;
        vector<vector<int> > g(n+2,vector<int>(m+2,0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>g[i][j];
                if (g[i][j]) g[i][j] = -1;
                else g[i][j] = 1;
                g[i][j] += g[i-1][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int len = 0;
                for (int k = 1; k <= m; ++k) {
                    int sum = 0;
                    for (int l = k; l >= 1; --l) {
                        sum += (g[j][l]-g[i-1][l]);
                        if (sum > 0) len = max(len,k-l+1);
                    }
                }
                ans = max(ans,len*(j-i+1));
                //cout<<i<<' '<<j<<' '<<len<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

