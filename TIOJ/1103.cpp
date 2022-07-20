#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

const int mod = 10000;
int dp[2][10005] = {0};
int ans[10005];
    
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    for (int i = 0;i <= 10000; ++i) dp[0][i] = 1;
    
    for (int i = 1; i <= 20000; ++i) {
        int cur = i%2, pre = (i+1)%2;
        for (int j = 0; j <= 10000; ++j) {
            if (i > (j<<1)) dp[cur][j] = 0;
            else dp[cur][j] = dp[cur][j-1]+dp[pre][j];
            dp[cur][j] %= mod;
            if (i == (j<<1)) ans[j] = dp[cur][j];
            //cout<<dp[cur][j]<<' ';
        }
        //cout<<endl;
    }

    while(cin>>n && n) {
        if (n >= 10) {
            cout<<setw(4)<<setfill('0')<<ans[n]<<endl;
        } else {
            cout<<ans[n]<<endl;
        }
    }

    return 0;
}
