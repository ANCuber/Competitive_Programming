#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
//#define endl '\n'

int dx[24] = {2,2,2,2,2,-2,-2,-2,-2,-2,1,1,-1,-1,0,0,0,0,1,-1-1,1,-1,1};
int dy[24] = {2,1,0,-1,-2,2,1,0,-1,-2,2,-2,2,-2,2,-2,1,-1,0,0,1,1,-1,-1};
int a, b, c;

void dfs(int x, int y, vector<vector<int> > &g) {
    g[x][y] = 0;
    for (int i = 0; i < 24; ++i) {
        if (x+dx[i] < 0 || y+dy[i] < 0 || x+dx[i] > a+1 || y+dy[i] > b+1) continue;
        if (g[x+dx[i]][y+dy[i]]) {
            dfs(x+dx[i],y+dy[i],g);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>a>>b>>c;
    vector<vector<int> > g(a+2,vector<int>(b+2,0));
    int x, y, cnt = 0;
    while(c--) {
        cin>>x>>y;
        g[x][y] = 1;
    }
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (g[i][j]) {
                dfs(i,j,g);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

