#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    int ans = 0, cnt = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        if (!pre && a < 0) {
            pre = 1;
            cnt++;
        }
        if (a > 0) pre = 0;
        ans += abs(a);
    }
    cout<<ans<<' '<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
