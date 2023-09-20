#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const long double esp = 1e-12;
int n, k;

bool check(long double m, vector<long double> &a, vector<long double> &b) {
    long double mx = -1e18;
    vector<long double> dp(n+2,0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i-1],(long double)(0.0))+a[i]-a[i-1]-m*(b[i]-b[i-1]);
        if (i >= k) {
            mx = max(mx,max((long double)(0.0),dp[i-k])+a[i]-a[i-k]-m*(b[i]-b[i-k]));
        }
    }
    return mx >= -esp;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k; 
    vector<long double> a(n+2,0), b(n+2,0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        cin>>b[i];
        b[i] += b[i-1];
    }
    
    long double l = 0, r = 1e6, mid;
    while(r-l > esp) {
        mid = (l+r)/2;
        if (check(mid,a,b)) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(10)<<(l+r)/2<<endl;
    return 0;
}
