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
        int n; cin>>n;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin>>a;
            if (a == 1) x++;
            else y++;
        }
        y += x/2;
        if (x&1) y++;
        cout<<y<<endl;
    }
    
    return 0;
}
