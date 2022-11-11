#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>m) {
        vector<vector<int> > ans(n+2,vector<int>(m+2,'0'));
        vector<vector<int> > g(n+2,vector<int>(m+2,0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin>>g[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!g[i][j]) continue;
                ans[i][j] = 'X';
                for (int k = 0; k < 8; ++k) {
                    if (ans[i+dx[k]][j+dy[k]] != 'X') ans[i+dx[k]][j+dy[k]]++;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j != 1) printf(" ");
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
