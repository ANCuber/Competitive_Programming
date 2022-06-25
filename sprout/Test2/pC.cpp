#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector <vector<int> > g(n+1,vector<int>(n+1,0));
    while(m--) {
        int u, v, l;
        cin>>u>>v>>l;
        g[u][v] = g[v][u] = l;
    }
    
}