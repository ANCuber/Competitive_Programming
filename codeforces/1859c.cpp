#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        int n; cin>>n;
        int sum = 0;
        for (int i = 1; i <= n-2; ++i) {
            sum += i*i;
        }
        cout<<sum+n*(n-1)<<endl;
    }
    return 0;
}
