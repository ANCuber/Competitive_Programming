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
    vector<vector<int> > anc(n+1,vector<int>(__lg(n)+5,-1));
    anc[1][0] = -1;
    for (int i = 2; i <= n; ++i) {
        int e; cin>>e;
        anc[i][0] = e;
    }
    for (int i = 1; i <= __lg(n)+1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (anc[j][i-1] > 0) anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    while(q--) {
        int x, k;
        cin>>x>>k;
        int base = 0;
        while(k) {
            if (k&1) {
                x = anc[x][base];
            }
            if (x < 0) break;
            base++;
            k >>= 1;
        }
        cout<<x<<endl;
    }
    return 0;
}
