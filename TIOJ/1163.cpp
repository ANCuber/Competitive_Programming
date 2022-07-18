#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Edge{
    int x, y;
    int d;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int V, E; cin>>V>>E;
    vector <Edge> e(E);
    for (int i = 0; i < E; ++i) {
        cin>>e[i].x>>e[i].y>>e[i].d;
    }
    int q; cin>>q;
    int st, ed;
    while(q--) {
        cin>>st>>ed;
        
    }
    return 0;
}
