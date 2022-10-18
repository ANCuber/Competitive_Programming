#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, st; cin>>n>>st;
    vector<int> grs(n);
    vector<vector<ll> > dp(n,vector<ll>(n,1e18));
    for (int i = 0; i < n; ++i) cin>>grs[i];
    sort(grs.begin(),grs.end());
    for (int i = 0; i < n; ++i) dp[i][i] = abs(grs[i]-st); 
}
