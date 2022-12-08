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
    ll n; cin>>n;    
    ll tar = n*(n+1)/2;
    if (tar&1) {
        cout<<"NO\n";
        return 0;
    }
    
    return 0;
}
