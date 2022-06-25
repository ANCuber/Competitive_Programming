#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Edge {
    int u, v;
    int w;
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector <Edge> e(m);
    for (int i = 0; i < m; ++i) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

}