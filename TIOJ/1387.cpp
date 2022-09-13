#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

struct Rock{
    int w, m, c;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Rock> br(n);
    for (int i = 0; i < n; ++i) cin>>br[i].w>>br[i].m>>br[i].c;
    int t; cin>>t;
    vector<Rock> r; 
    r.push_back({0,0,0});
    for (int i = 0; i < n; ++i) {
        int s = 1;
        while(br[i].c > s) {
            r.push_back({br[i].w*s,br[i].m*s,s});
            br[i].c -= s;
            s <<= 1;
        }
        r.push_back({br[i].w*(br[i].c),br[i].m*(br[i].c),br[i].c});
    }
    vector<vector<int> > dp(2,vector<int>(t+1,-1e9));
    dp[0][0] = 0;

    for (int i = 1; i < r.size(); ++i) {
        for (int j = 0; j <= t; ++j) {
            if (j >= r[i].w) dp[i%2][j] = max(dp[(i+1)%2][j],dp[(i+1)%2][j-r[i].w]+r[i].m);
            else dp[i%2][j] = dp[(i+1)%2][j];
        }
    }
    int ans = -1e9;
    for (int i = 0; i <= t; ++i) {
        ans = max(ans,dp[(r.size()+1)%2][i]);
    }
    cout<<ans<<endl;
    
    return 0;
}
