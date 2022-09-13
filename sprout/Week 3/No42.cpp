#include <bits/stdc++.h>
using namespace std;

int dx[4] = {+1,-1,+0,+0};
int dy[4] = {+0,+0,+1,-1};

int h, w;

void PoolAmount(vector <vector <bool> > &yard, int x, int y) {
    yard[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        if (x+dx[i]<h && x+dx[i]>-1 && y+dy[i]<w && y+dy[i]>-1) {
            if (yard[x+dx[i]][y+dy[i]]) PoolAmount(yard,x+dx[i],y+dy[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>h>>w;
        vector <vector <bool> > yard(h);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char x; cin>>x;
                if (x == '.') yard[i].push_back(1);
                else yard[i].push_back(0);
            }
        }
        long long ans = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (yard[i][j] == 1) {
                    PoolAmount(yard,i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
} 