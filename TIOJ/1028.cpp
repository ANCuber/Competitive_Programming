#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<int> > graph(n,vector<int>(n,1e9));
    for (int i = 0; i < m; ++i) {
        int a, b; cin>>a>>b;
        int d; cin>>d;
        graph[a][b] = d;
        graph[b][a] = d;
    }
    int k; cin>>k;
    vector<int> des(k);
    for (int i = 0; i < k;++i) cin>>des[i];
    
}