#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int a = 0;
    int sx, sy, x, y, px, py;
    for (int i = 0; i < n; ++i) {
        if (!i) {
            cin>>sx>>sy;
            px = sx, py = sy;
            continue;
        }
        cin>>x>>y;
        a += (px*y-py*x);
        px = x, py = y;
    }
    a += (x*sy-y*sx);
    cout<<abs(a)<<endl;
    return 0;
}
