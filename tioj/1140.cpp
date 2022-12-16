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
    int n; cin>>n;
    cout<<fixed<<setprecision(4);
    long double sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long double r, g, b;
            cin>>r>>g>>b;
            cout<<0.5149*r+0.3244*g+0.1607*b;
            cout<<' '<<0.2654*r+0.6704*g+0.0642*b;
            cout<<' '<<0.0248*r+0.1248*g+0.8504*b;
            cout<<endl;
            sum += 0.2654*r+0.6704*g+0.0642*b;
        }
    }
    cout<<"The average of Y is "<<sum/(n*n)<<endl;
    return 0;
}
