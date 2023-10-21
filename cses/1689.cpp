#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int sol[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,6,19,58,37,4,17,60,47},
    {0,57,38,5,18,59,48,15,62},
    {0,20,7,36,3,16,61,46,49},
    {0,39,56,29,32,35,2,63,14},
    {0,8,21,34,1,30,27,50,45},
    {0,55,40,31,28,33,64,13,26},
    {0,22,9,42,53,24,11,44,51},
    {0,41,54,23,10,43,52,25,12}
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y; cin>>x>>y;    
    int tmp = sol[y][x];
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            if (j-1) cout<<' ';
            cout<<(sol[i][j]-(tmp)+64)%64+1;
        }
        cout<<'\n';
    }
    return 0;
}
