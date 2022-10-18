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
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int x, y, z, ans = 0;
    for (int i = 0; i <= min(a,b); ++i) {
        if (ans < i*100+min(a-i,c)*80+min(b-i,d)*60) {
            ans = i*100+min(a-i,c)*80+min(b-i,d)*60;
            y = i, x = min(a-i,c), z = min(b-i,d);
        }
    }
    cout<<x<<' '<<y<<' '<<z<<endl;
    cout<<ans<<endl;
    return 0;
}
