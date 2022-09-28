#pragma GCC optimize("Ofast,unroll-loops")
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
    int n, p;    
    while(cin>>n>>p && (n+p)) {
        vector<ll> dp(p+1,0);
        dp[0] = 1;
        while(n--) {
            int a; cin>>a;
            for (int i = a; i <= p; ++i) {
                dp[i] += dp[i-a];
            }
        }
        cout<<dp[p]<<endl;
    }
    return 0;
}
