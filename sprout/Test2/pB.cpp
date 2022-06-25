#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Edge {
    int u, v;
    int w;
};

bool cmp1(Edge a, Edge b) {
    return a.w > b.w;
}

bool cmp2(Edge a, Edge b) {
    return a.w < b.w;
}

int find_boss(vector <int> &boss, int x) {
    if (boss[x] == x) return x;
    return boss[x] = find_boss(boss,boss[x]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    ll ans = 0;
    vector <int> boss(n+1);
    for (int i = 1; i <= n; ++i) boss[i] = i;
    vector <Edge> e(m);
    map<pair<int,int>,int> mst;
    for (int i = 0; i < m; ++i) {
        int a, b; cin>>a>>b;
        e[i].u = min(a,b);
        e[i].v = max(a,b);
        cin>>e[i].w;
    }
    sort(e.begin(),e.end(),cmp1);
    int minn = 1e9+5;
    for (int i = 0; i < m; ++i) {
        Edge cur = e[i]; 
        if (find_boss(boss,cur.u) == find_boss(boss,cur.v)) {
            continue;
        } else {
            boss[find_boss(boss,cur.u)] = find_boss(boss,cur.v);
            minn = cur.w;
        }
    }
    for (int i = 1; i <= n; ++i) boss[i] = i;
    sort(e.begin(),e.end(),cmp2);
    for (int i = 0; i < m; ++i) {
        if (e[i].w < minn) continue;
        Edge cur = e[i]; 
        if (find_boss(boss,cur.u) == find_boss(boss,cur.v)) {
            continue;
        } else {
            boss[find_boss(boss,cur.u)] = find_boss(boss,cur.v);
            ans += cur.w;
        }
    }
    cout<<ans<<endl;
    return 0;
}