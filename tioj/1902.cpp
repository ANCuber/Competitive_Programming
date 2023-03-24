#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;
    vector<int> a(N+2,0);
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        a[i] |= a[i-1];
    }
    while(q--) {
        int l, r; cin>>l>>r;
        
    }
    
    return 0;
}
