#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    
    if ((b-d)*(c-e) == (d-f)*(a-c) && ((a-c)||(b-d)) && ((c-e)||(d-f)) && ((a-e)||b-f)) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;    
    while(T--) Run();
    return 0;
}
