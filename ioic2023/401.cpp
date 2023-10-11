#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define ld double

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    cout<<fixed<<setprecision(15);
    if (n == 3) {
        cout<<0<<' '<<1<<endl;
        cout<<-1<<' '<<0<<endl;
        return 0;
    }
    ld a = 0.0, b = 1.0;
    ld k = 1.0/(n-2);
    ld tk = k;
    ld area = 0;
    vector<pair<ld,ld> > v(n);
    for (int i = 1; i <= n-3; ++i) {
        ld y = sqrt(1-k*k);
        v[i] = {k,y};
        //cout<<k<<' '<<y<<endl;
        //cout<<"VAL:"<<k*k+y*y<<endl;
        //area += ((k)*(b)-(a)*(y));
        a = k, b = y;
        k += tk;
    }
    ld val = 0, px = 1, py = 0;
    for (int i = n-3; i > 0; --i) {
        cout<<v[i].first<<' '<<v[i].second<<endl;
        area += px*v[i].second-py*v[i].first;
        //px = v[i].first, py = v[i].second;
    }
    area += (-1.0*a);
    area += (-1.0);
    area = area/2.0;
    //cout<<area<<endl;
    ld C = 1.0-area;
    cout<<0<<' '<<1<<endl; 
    ld A = (ld)((1-C)*(1-C)-1)/2.0, B = 1.0-C;
    cout<<(ld)(B+sqrt(B*B-4*A))/2.0<<' '<<(ld)(B-sqrt(B*B-4*A))/2.0<<endl;
    //cout<<"AREA:"<<area+1-((ld)(B+sqrt(B*B-4*A))/2.0)-((ld)(B-sqrt(B*B-4*A))/2.0)<<endl;
    return 0;
}
