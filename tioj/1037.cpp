#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int n, m, x1, y_1, x2, y2, k, d, cx, cy;
int g[2][102][102] = {0};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

signed main() {
    scanf("%d%d%d%d%d%d%d",&n,&m,&x1,&y_1,&x2,&y2,&k);
    //x1++,y_1++,x2++,y2++;
    g[0][x1][y_1] = 1;
    for (int t = 1; t <= k; ++t) {
        scanf("%d",&d);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                g[t%2][i][j] = 0;
                for (int l = 0; l < 4; ++l) {
                    cx = i+d*dx[l], cy = j+d*dy[l];
                    if (cx < 0) cx += 500;
                    if (cy < 0) cy += 500;
                    cx %= n, cy %= m;
                    g[t%2][i][j] |= g[(t+1)%2][cx][cy];
                }
            }
        }
    }
    if (g[k%2][x2][y2]) printf("YES\n");
    else printf("NO\n");
    return 0;
}
