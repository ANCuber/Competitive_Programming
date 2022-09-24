#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;

inline int id(int x, int y) { return x*n+y;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<int> g(n*n);
    vector<vector<int> > d(n*n,vector<int>(n*n,1e9));
    for (int i = 0; i < n*n; ++i) d[i][i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>g[id(i,j)];
            if (i) {
                d[id(i,j)][id(i-1,j)] = g[id(i-1,j)];
                d[id(i-1,j)][id(i,j)] = g[id(i,j)];
            }
            if (j) {
                d[id(i,j)][id(i,j-1)] = g[id(i,j-1)];
                d[id(i,j-1)][id(i,j)] = g[id(i,j)];
            }
        }
    }

    for (int k = 0; k < n*n; ++k) {
        for (int i = 0; i < n*n; ++i) {
            for (int j = 0; j < n*n; ++j) {
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    int q; cin>>q;
    int sx, sy, tx, ty;
    while(q--) {
        cin>>sx>>sy>>tx>>ty;
        sx--,sy--,tx--,ty--;
        int ans = d[id(sx,sy)][id(tx,ty)];
        for (int i = 0; i < n*n; ++i) {
            ans = min(ans,d[id(sx,sy)][i]+d[i][id(tx,ty)]-g[i]);
        }
        cout<<ans+g[id(sx,sy)]<<endl;
    }
    return 0;
}
