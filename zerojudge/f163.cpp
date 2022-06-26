#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n, m;

struct Node{
    int l = 0;
    int r = 0;
    int w = 0;
};


int init(int node, vector <Node> &graph) {
    if (node >= n) return graph[node].w;
    graph[node].w += (init(graph[node].l,graph)+init(graph[node].r,graph));
    return graph[node].w;
}

int push(int cw, int node,vector <Node> &graph) {
    if (node >= n) {
        graph[node].w += cw;
        return node;
    }
    graph[node].w += cw;
    if (graph[graph[node].l].w <= graph[graph[node].r].w) {
        return push(cw,graph[node].l,graph);
    } else {
        return push(cw,graph[node].r,graph);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector <Node> graph(2*n);
    for (int i = n; i <= 2*n-1; ++i) {
        cin>>graph[i].w;
    }
    vector <int> ws(m);
    for (int i = 0; i < m; ++i) {
        cin>>ws[i];
    }
    
    for (int i = 1; i <= n-1; ++i) {
        int a, b, c; cin>>a>>b>>c;
        graph[a].l = b;
        graph[a].r = c;
    }
    init(1,graph);
    for (int i = 0; i < m; ++i) {
        if (i) cout<<' ';
        cout<<push(ws[i],1,graph);
    }
    cout<<endl;
    return 0;
}