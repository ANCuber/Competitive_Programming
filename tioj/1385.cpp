#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    getline(cin,a);
    getline(cin,b);
    vector<vector<int> > dp(a.size()+5,vector<int>(b.size()+5));
    dp[0][0] = (a[0] != b[0]);
    for (int i = 0; i <= a.size(); ++i) {
        for (int j = 0; j <= b.size(); ++j) {
            if (!i || !j) dp[i][j] = max(i,j);
            else dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1*(a[i-1]!=b[j-1])});
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}
