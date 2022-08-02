#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n, m, xa, ya, xb, yb, xc, yc, xd, yd;
        cin>>n>>m>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        int dy[4];
        dy[0] = ya, dy[1] = yb, dy[2] = yc, dy[3] = yd;
        sort(dy,dy+4);
        if (xa > xb) swap(xa,xb), swap(ya,yb);
        if (xc > xd) swap(xc,xd), swap(yc,yd);
        if (xa > xc) {
            swap(xa,xc);
            swap(ya,yc);
            swap(xb,xd);
            swap(yb,yd);
        }
        if (xb < xc || max(ya,yb) < min(yc,yd) || max(yc,yd) < min(ya,yb)) {
            cout<<0<<endl;
            continue;
        }
        int ans;
        
        if (ya == yb || yc == yd) ans = xb-xc; 
        else if (xa == xb || xc == xd) ans = dy[2]-dy[1];
        else if ((ya-yb)*(yc-yd) < 0) {
            ans = max(xb-xc+1,dy[2]-dy[1]+1);
        } else {
            ans = (xb-xc+1)+(dy[2]-dy[1])-1;
        }
        cout<<ans<<endl;
   }
   return 0;
}
