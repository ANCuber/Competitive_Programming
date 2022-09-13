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
    int t, n; cin>>t;    
    ll dp[15];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 13; ++i) dp[i] = dp[i-1]*i;
    for (int j = 1; j <= t; ++j) {
        cout<<"Case #"<<j<<":\n";
        cin>>n;
        for (int i = 0; i <= n; ++i) {
            cout<<"TFCIS"<<i<<"="<<dp[i]<<endl;
        }
    }
    return 0;
}
