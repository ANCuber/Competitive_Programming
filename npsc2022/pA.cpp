#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mxsz = 4e3;

vector<vector<int> > g(mxsz+5,vector<int>(mxsz+5,0));


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    char x;
    g[1][1] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>x; 
            if (x == 'P') {
                g[i][j] = 1;
            }
        }
    }
    
    return 0;
}
