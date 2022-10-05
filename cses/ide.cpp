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
    int n, q; cin>>n>>q;    
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i] ^= arr[i-1];
    }
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<(arr[l-1]^arr[r])<<endl;
    }
    
    return 0;
}
