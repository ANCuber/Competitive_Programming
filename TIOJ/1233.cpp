#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int m, n;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};
int a[15] = {0,1,2,4,6,10,12,14,16,18,20};

void fill(int x, int y, vector<vector<int> > &g) {
    g[x][y] = 0;
    for (int i = 0; i < 8; ++i) {
        if (g[x+dx[i]][y+dy[i]]) {
            fill(x+dx[i],y+dy[i],g);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;
    char x;
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>x;
            g[i][j] = (x == '1');
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(g[i][j]) {
                fill(i,j,g);
                ans++;
            }
        }
    }
    if(ans > 20) cout<<10<<endl;
    for (int i = 0; i <= 10; ++i) {
        if (a[i] >= ans) {
            cout<<i<<endl;
            return 0;
        }
    }
    
    return 0;
}
