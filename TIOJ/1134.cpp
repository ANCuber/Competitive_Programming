#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n, m;
    while(t--) {
        cin>>n>>m;
        vector<vector<int> > g(205,vector<int>(205,0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>g[i][j];
                g[i][j] = 1-g[i][j];
                g[i][j] += g[i-1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                int lp = 0 , cnt = 0;
                for (int k = 1; k <= m; ++k) {
                    cnt += g[j][k]-g[i][k];
                    while (lp < k && cnt <= (k-lp)*(j-i)-cnt) {
                        cnt -= g[j][++lp]-g[i][lp];
                    }
                    if (cnt > (k-lp)*(j-i)-cnt) ans = max(ans,(k-lp)*(j-i));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}





