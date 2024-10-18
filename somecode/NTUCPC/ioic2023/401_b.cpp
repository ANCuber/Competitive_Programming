#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define ld long double

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    cout<<fixed<<setprecision(15);
    ld k = 1e-15, b = 1e-15;
    for (int i = 0; i < n-3; ++i) {
        cout<<1-k<<' '<<k<<endl;
        k += b;
    }
    cout<<0<<' '<<1<<endl;
    cout<<-1<<' '<<0<<endl;
    return 0;
}
