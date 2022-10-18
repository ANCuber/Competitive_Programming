#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

void debug(int tmp) {
    while(tmp) {
        cout<<(tmp&1);
        tmp >>= 1;
    }
    cout<<endl;
}

int slv(int s, vector<vector<int> > &r, vector<int> &dp) {
    if (!s) return 0;
    if (dp[s]) return dp[s];
    //debug(s);
    int i = s&-s, ans = 1e9;
    for (int j = __lg(i)+1; j < n; ++j) {
        if ((1&(s>>j)) == 0) continue;
        for (int k = j+1; k < n; ++k) {
            if ((1&(s>>k)) == 0) continue;
            ans = min(ans,slv(s^i^(1<<j)^(1<<k),r,dp)+r[__lg(i)][j]+r[j][k]+r[k][__lg(i)]);
        }
    }
    return dp[s] = ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<int> > r(n,vector<int>(n,0));
        vector<int> dp((1<<n),0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>r[i][j];
            }
        }
        cout<<slv((1<<n)-1,r,dp)<<endl;
    }
    return 0;
}

