#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > graph;
vector <int> color;
int controller;

void dfs(int node, int c) {
    //cout<<"pass";
    for (int i = 0; i < graph[node].size(); ++i) {
        if (!color[graph[node][i]]) {
            color[graph[node][i]] = 3-c;
            dfs(graph[node][i],3-c);
        } else {
            if (c == color[graph[node][i]]) {
                controller = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(true) {
        cin>>n>>m;
        controller = 1;
        if (n == 0 && m == 0) break;
        graph.clear();
        graph.resize(n+1);
        color.resize(n+1);
        fill(color.begin(), color.end(), 0);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1,1);
        for (int i = 2; i <= n; ++i) {
            if (!color[i]) dfs(i,1);
        }
        if (controller) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}