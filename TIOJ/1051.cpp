#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int s; cin>>s;
        vector<string> a(s+1), b(s+1); 
        for (int i = 1; i <= s; ++i) cin>>a[i];
        for (int i = 1; i <= s; ++i) cin>>a[i];
        
        
        
        cout<<dp[s][s]<<endl;
    }
    return 0;
}