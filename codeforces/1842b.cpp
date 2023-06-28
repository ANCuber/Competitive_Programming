#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n, x; cin>>n>>x;
    int a[3] = {0,0,0};
    for (int i = 0; i < 3; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            int u; cin>>u;
            cur |= u;
            if ((cur|x) == x) a[i] = cur;
        }
    }
    if ((a[0]|a[1]|a[2]) == x) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
