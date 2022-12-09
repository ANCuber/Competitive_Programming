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
    int k, n; cin>>k>>n;    
    vector<vector<int> > p(n,vector<int>(2*k+1)),u(n,vector<int>(2*k+1)),l(n,vector<int>(2*k+1));
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
        for (int j = 0; j < 2*k+1; ++j) cin>>p[i][j];
        for (int j = 0; j < 2*k+1; ++j) cin>>u[i][j];
        for (int j = 0; j < 2*k+1; ++j) cin>>l[i][j];
    }
    int nor = 0, abn = 0;
    for (int i = 0; i < n; ++i) {
        int flag = 1;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            
        }
        if (flag) nor = max(nor,s[i]);
    }
    
    cout<<nor<<' '<<abn<<endl;
    return 0;
}
