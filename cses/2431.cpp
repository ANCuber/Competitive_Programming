#pragma GCC optimize("O3")
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
        ll k; cin>>k;
        ll bs = 9;
        while(k > 0) {
            k -= bs;
            bs *= 10;
        }
        bs /= 10;
        k += bs;
    }
    
    return 0;
}
