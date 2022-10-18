#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r, c;
    while(cin>>r>>c) {
        vector<vector<int> > g(r+2,vector<int>(c+2,0));
        int x;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cin>>x;
                if (x == 1) {
                    g[i][j] = 1e8;
                    for (int k = 0; k < 8; ++k) {
                        g[i+dx[k]][j+dy[k]]++;
                    }
                }
            }
        }
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (j != 1) cout<<' ';
                if (g[i][j] >= 1e8) {
                    cout<<'X';
                } else {
                    cout<<g[i][j];
                }
            }
            cout<<endl;
        }
    }
}
