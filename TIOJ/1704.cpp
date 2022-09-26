#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector< pii > v(n+1);
    vector<vector<int> > a(n+1,vector<int>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin()+1,v.end());
    v[0] = {0,0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>a[i][j];
        }
    }
    
    vector<vector< pii > > dp(n+1,vector< pii >(n+1,{0,0}));
    for (int i = 1; i <= n; ++i) {
        int mx = -1, mxid = 0;
        for (int j = 0; j <= n; ++j) {
            if (mx < dp[i-1][j].first) {
                mxid = j;
                mx = dp[i-1][j].first;
            }
            dp[i][j].first = mx+a[v[i].second][j];
            if (mxid != j) dp[i][j].second++;
            
            //cout<<dp[i][j].first<<' ';
            if (dp[i][j].first >= k) {
                cout<<dp[i][j].second<<endl;
                return 0;
            }
        }
        //cout<<endl;
    }
    cout<<-1<<endl;
    
    return 0;
}
