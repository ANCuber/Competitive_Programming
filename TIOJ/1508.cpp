#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

string ans[2] = {"No","Yes"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    vector<int> a(n+1);
    while(m--) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            sum += a[i];
        }
        if (sum&1) {
            cout<<"No"<<endl;
            continue;
        }
        vector<vector<int> > dp(2,vector<int>(sum/2+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum/2; ++j) {
                if (j >= a[i]) dp[i%2][j] = max(dp[(i+1)%2][j],dp[(i+1)%2][j-a[i]]);
                else dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
        cout<<ans[dp[n%2][sum>>1]]<<endl;
    }
    return 0;
}
