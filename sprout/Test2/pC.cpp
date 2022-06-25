#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector <vector<ll> > g(n+1,vector<ll>(n+1,1e12));
    while(m--) {
        int u, v;
        ll l;
        cin>>u>>v>>l;
        g[u][v] = g[v][u] = l;
    }
    
    return 0;
}