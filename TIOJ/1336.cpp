#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

void dfs(int x, int y, vector<vector<int> > &gr, int tp) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, h; cin>>w>>h;
    vector<vector<int> > g(h+2,vector<int>(w+2,0)), sp;
    char a;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin>>a;
            if (a == '-') {
                g[i][j] = 1;
            } else if (a == 'G') {
                g[i][j] = 2;
            }
        }
    }
    sp = g;
    int green = 0, space = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            
        }
    }
    return 0;
}
