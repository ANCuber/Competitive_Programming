#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<vector<int> > des(31,vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        cin>>des[0][i];
    }
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= n; ++j) {
            des[i][j] = des[i-1][des[i-1][j]];
        }
    }
    while(q--) {
        int x, k; cin>>x>>k;
        int base = 0;
        while(k) {
            if (k&1) x = des[base][x];
            base++;
            k >>= 1;
        }
        cout<<x<<endl;
    }
    return 0;
}
