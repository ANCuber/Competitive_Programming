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
    int sum = 0, x=0,y=0,z=0;
    sum += min(a,b)*100;
    y = min(a,b);
    a -= y, b -= y;
    while(min(c,d)>0 && y>0) {
        sum += 40;
        y--, x++, z++;
        c--, d--;
    }
    sum += min(a,c)*80;
    x += min(a,c);
    sum += min(b,d)*60;
    z += min(b,d);
    
    cout<<x<<' '<<y<<' '<<z<<endl;
    cout<<sum<<endl;
    
    return 0;
}
