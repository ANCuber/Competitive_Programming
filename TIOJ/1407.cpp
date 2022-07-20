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
    vector<Rock> r(n+1);
    for (int i = 1; i <= n; ++i) cin>>r[i].w>>r[i].m>>r[i].c;
    int t; cin>>t;
    vector<vector<int> > dp(2,vector<int>(t+1,-1e9));
    vector<int> mx(t+1,-1e9);
    vector<deque< pii > > q(1005);//weight, value
    dp[0][0] = mx[0] = 0;

    for (int i = 1, w, m, c; i <= n; ++i) {
        w = r[i].w, m = r[i].m, c = r[i].c;
        for (int j = 0; j <= t; ++j) {
            if (j < w) {
                q[j].clear();
                dp[i%2][j] = dp[(i+1)%2][j];
                q[j].push_back({j,dp[(i+1)%2][j]});
                continue;
            }
            int id = j%w;
            while(!q[id].empty() && q[id].front().first < j-c*w) {
                q[id].pop_front();
            }
            int tmp = q[id].front().second + (j-q[id].front().first)/w*m;
            while(!q[id].empty() && q[id].back().second + (j-q[id].back().first)/w*m <= dp[(i+1)%2][j]) {
                q[id].pop_back();
            }
            q[id].push_back({j,dp[(i+1)%2][j]});
            dp[i%2][j] = max(dp[(i+1)%2][j],tmp);
        }
    }

    int ans = -1;
    for (int i = 0; i <= t; ++i) {
        ans = max(ans,dp[n%2][i]);
    }
    cout<<ans<<endl;
     
    return 0;
}
