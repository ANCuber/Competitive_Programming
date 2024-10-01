#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int cal(vector<vector<int> > &w, vector<vector<int> > &g, int m, int n) {
    int ret = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) ret += (g[i][j] || w[i][j]);
    return ret;
}

int check(vector<vector<int> > &w, int m, int n, int r, int c) {
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (int i = r-1; i >= 0; --i) if (w[i][c]) f1 = 1;
    for (int i = r+1; i < m; ++i) if (w[i][c]) f2 = 1;
    for (int i = c-1; i >= 0; --i) if (w[r][i]) f3 = 1;
    for (int i = c+1; i < n; ++i) if (w[r][i]) f4 = 1;
    return f1+2*f2+4*f3+8*f4;
}

void add(vector<vector<int> > &w, vector<vector<int> > &g, int m, int n, int r, int c) {
    g[r][c] = 0;
    w[r][c] = 1;
    int tmp = check(w,m,n,r,c);

    if ((tmp&1) && (tmp&2)) {
        for (int i = r-1; i >= 0 && g[i][c]; --i) g[i][c]--;
        for (int i = r+1; i < m && g[i][c]; ++i) g[i][c]--;
    }
    if ((tmp&4) && (tmp&8)) {
        for (int i = c-1; i >= 0 && g[r][i]; --i) g[r][i]--;
        for (int i = c+1; i < n && g[r][i]; ++i) g[r][i]--;
    }

    for (int i = r-1; i >= 0; --i) {
        if (w[i][c]) {
            for (int j = r-1; j > i; --j) g[j][c]++;
            break;
        }
    }
    for (int i = r+1; i < m; ++i) {
        if (w[i][c]) {
            for (int j = r+1; j < i; ++j) g[j][c]++;
            break;
        }
    }
    for (int i = c-1; i >= 0; --i) {
        if (w[r][i]) {
            for (int j = c-1; j > i; --j) g[r][j]++;
            break;
        }
    }
    for (int i = c+1; i < n; ++i) {
        if (w[r][i]) {
            for (int j = c+1; j < i; ++j) g[r][j]++;
            break;
        }
    }
}

void del(vector<vector<int> > &w, vector<vector<int> > &g, int m, int n, int r, int c) {
    int tmp = check(w,m,n,r,c);
    w[r][c] = 0;
    if (tmp&1) for (int i = r-1; i >= 0 && g[i][c] > 0; --i) g[i][c]--;
    if (tmp&2) for (int i = r+1; i < m && g[i][c] > 0; ++i) g[i][c]--;
    if (tmp&4) for (int i = c-1; i >= 0 && g[r][i] > 0; --i) g[r][i]--;
    if (tmp&8) for (int i = c+1; i < n && g[r][i] > 0; ++i) g[r][i]--;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n, h; cin>>m>>n>>h;
    vector<vector<int> > g(m,vector<int>(n,0)), w(m,vector<int>(n,0));
    int mx = 0;
    while(h--) {
        int r, c, t; cin>>r>>c>>t;
        if (!t) add(w,g,m,n,r,c);
        else del(w,g,m,n,r,c);
        mx = max(mx,cal(w,g,m,n));
    }
    cout<<mx<<'\n';
    cout<<cal(w,g,m,n)<<'\n';
    return 0;
}
