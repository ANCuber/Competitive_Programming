#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n, m, k;

struct Info{
    int bmb = 0;
    bool emp = 0;
};

struct Boss{
    int r, c, s, t;
    bool live = 1;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    vector<vector<Info> > g(n+2,vector<Info>(m+2));
    vector<Boss> b(k+2);
    for (int i = 1; i <= k; ++i) {
        cin>>b[i].r>>b[i].c>>b[i].s>>b[i].t;
    }
    int rem = k;
    while(rem) {
        for (int i = 1; i <= k; ++i) if (b[i].live) g[b[i].r][b[i].c].bmb++;//Place bumbs
        for (int i = 1; i <= k; ++i) {//Moving
            if (!b[i].live) continue;
            b[i].r += b[i].s, b[i].c += b[i].t;
            if (b[i].r < 0 || b[i].r >= n || b[i].c < 0 || b[i].c >= m) {
                b[i].live = 0;
                rem--;
                continue;
            }
            if (g[b[i].r][b[i].c].bmb) {
                b[i].live = 0;
                rem--;
                g[b[i].r][b[i].c].emp = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j].emp) g[i][j].bmb = 0;
                g[i][j].emp = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += (g[i][j].bmb > 0);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
