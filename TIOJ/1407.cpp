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
    vector<vector<int> > dp(2,vector<int>(t+1,-1e9));//m-i*_n
    vector<int> mx(t+1,-1e9);
    dp[0][0] = mx[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= t; ++j) {
            if (dp[(i+1)%2][]) {
                
            } else {
                
            }
        }
    }
     
    return 0;
}
