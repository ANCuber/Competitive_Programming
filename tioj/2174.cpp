#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Ope{
    int pos, tim, val;
    bool operator<(Ope y) {
        return pos < y.pos;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin>>N>>M;    
    int cmd, l, r, x;
    vector<Ope> p;
    vector<vector<int> > q(n+2);
    for (int i = 1; i <= M; ++i) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>l>>r>>x;
            p.pb({l,i,x});
            p.pb({r+1,i,-x})
        } else {
            cin>>x;
            q[x].pb(i);
        }
    }
    sort(p.begin(),p.end());
    for (int i = 1; i <= M; ++i) {
        
    }
    
    return 0;
}
