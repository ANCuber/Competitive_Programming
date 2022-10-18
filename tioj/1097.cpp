#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
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
    int l, w, a;
    while(cin>>l>>w && l && w) {
        vector<vector<int> > dp(2,vector<int>(w+1,0));
        int ans = 0;
        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin>>a;
                if (a == 2) a = 0;
                else a = 1;
                dp[i%2][j] = (min({dp[i%2][j-1],dp[(i+1)%2][j],dp[(i+1)%2][j-1]})+1)*a;
                ans = max(ans,dp[i%2][j]);
                //cout<<i<<' '<<j<<' '<<dp[i%2][j]<<endl;
            }
        }
        cout<<ans*ans<<endl;
    }
    return 0;
}
