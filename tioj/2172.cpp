#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int n, m, a, b;
int x, y;
vector<vector<int> > g;
vector <int> dep;
int anc[100005][25];

void dfs(int pre, int cur) {
    dep[cur] = dep[pre]+1;
    anc[cur][0] = pre;
    for (auto i : g[cur]) {
        if (i != pre) {
            dfs(cur,i);
        }
    }
}

void pre() {
    for (int i = 1; (1<<i) <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    g.resize(n), dep.resize(n);
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dep[0] = 0;
    dfs(0,0);
    pre();
    while(m--) {
        cin>>x>>y;
        if (dep[x] < dep[y]) swap(x,y);
        int ox = x, oy = y;
        int d = dep[x]-dep[y];
        for (int i = 0; (1<<i) <= d; ++i) {
            if((1<<i)&d) x = anc[x][i];
        }
        if (x == y) {
            cout<<d<<endl;
            continue;
        }
        for (int i = __lg(n); i >= 0; --i) {
            if (anc[x][i] != anc[y][i]) {
                x = anc[x][i];
                y = anc[y][i];
            }
        }
        cout<<dep[ox]+dep[oy]-2*dep[anc[x][0]]<<endl;
    }
    return 0;
}
