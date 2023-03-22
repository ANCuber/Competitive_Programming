#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

bool check(vector<int> &d, int mid) {
    vector<int> dp(n+2,0);
    dp[1] = 1;
    if (abs(d[2]-d[1]) <= mid) dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1]*(abs(d[i]-d[i-1])<=mid)) | (dp[i-2]*(abs(d[i]-d[i-2])<=mid));
    }
    return dp[n];
}

void Run() {
    cin>>n;
    vector<int> d(n+1);
    for (int i = 1; i <= n; ++i) cin>>d[i];
    int l = -1, r = 5e9;
    int mid = (l+r)>>1;
    while(r-l > 1) {
        if (check(d,mid)) r = mid;
        else l = mid;
        mid = (l+r)>>1;
    }
    cout<<r<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
