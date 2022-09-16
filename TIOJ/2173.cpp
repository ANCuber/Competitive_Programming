#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int long long

int m, n;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;    
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>g[i][j];
        }
    }
    int ans = 0;
    
    return 0;
}
