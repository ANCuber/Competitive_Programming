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
    while(t--){
        int n, a; cin>>n;
        int c = 10-n;
        while(n--) cin>>a;
        cout<<3*c*(c-1)<<endl;
    }
    
    return 0;
}
