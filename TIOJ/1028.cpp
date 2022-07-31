#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int n, m, k;
int u, v, c, st;
int gl = 0;
vector<vector<int> > g(15,vector<int>(15));

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>c;
        g[u][v] = g[v][u] = c;
    }
    cin>>k>>st;
    gl |= (1<<st);
    for (int i = 0; i < k-1; ++k) {
        int p; cin>>p;
        gl |= (1<<p);
    }
    
    return 0;
}
