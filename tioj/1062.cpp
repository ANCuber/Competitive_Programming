#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;
ll sum = 0, mx;
int x = 1, y = 1;

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d%d",&m,&n);
    vector<vector<ll> > g(m+2,vector<ll>(n+2,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld",&g[i][j]);
            sum += (i+j-2)*g[i][j];
        }
    }
    mx = sum;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            
        }
    }
    return 0;
}
