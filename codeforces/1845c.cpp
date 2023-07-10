#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    string s; cin>>s;
    int n = s.size();
    vector<vector<int> > a(n+2,vector<int> (12,1e9));
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) {
            if (s[i+1]-'0' == j) a[i][j] = i+1;
            else a[i][j] = a[i+1][j];
        }
    }
    int m; cin>>m;
    string l, r; cin>>l>>r;
    vector<vector<int> > dp(12,vector<int>(12,1e9));
    for (int i = 0; i < m; ++i) {
        int mx = -1;
        if (i) for (int k = l[i-1]-'0'; k <= r[i-1]-'0'; ++k) mx = max(mx,dp[i-1][k]);
        for (int j = 0; j < 10; ++j) {
            if (j<l[i]-'0' || j>r[i]-'0') continue;
        
            if (!i) {
                if (j == s[0]-'0') dp[i][j] = 0;
                else if (a[0][j] == 1e9) {
                    cout<<"YES"<<endl;
                    return;
                } else {
                    dp[0][j] = a[0][j];
                }
            } else {
                if (a[mx][j] == 1e9) {
                    cout<<"YES"<<endl;
                    return;
                } else {
                    dp[i][j] = a[mx][j];
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
