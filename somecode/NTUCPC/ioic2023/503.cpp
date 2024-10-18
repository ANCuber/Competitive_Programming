#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct POS{
    int x, y;
};

struct WALL{
    int sx, sy, tx, ty;
};

int sign(int y) {
    if (y > 0) return 1;
    else if (y < 0) return -1;
    else return 0;
}

int cross(int ax, int ay, int bx, int by) {
    return ax*by-bx*ay;
}

int ori(int a1, int a2, int b1, int b2, int c1, int c2) {
    return sign(cross(b1-a1,b2-a2,c1-a1,c2-a2));
}

int banana(WALL a, WALL b) {
    int a123 = ori(a.sx,a.sy,a.tx,a.ty,b.sx,b.sy);
    int a124 = ori(a.sx,a.sy,a.tx,a.ty,b.tx,b.ty);
    int a341 = ori(b.sx,b.sy,b.tx,b.ty,a.sx,a.sy);
    int a342 = ori(b.sx,b.sy,b.tx,b.ty,a.tx,a.ty);
    return a123*a124 < 0 && a341*a342 < 0;
}

struct ALLPOINT{
    int x, y, ty, id;
    bool operator<(ALLPOINT b) {
        int a = (sign(y) < 0 || (sign(y) == 0 && sign(x) < 0));
        int c = (sign(b.y) < 0 || (sign(b.y) == 0 && sign(b.x) < 0));
        if (a != c) return a < c;
        return sign(cross(x,y,b.x,b.y)) > 0;
    }
};

int n, m;

int solve(int cur, vector<POS> &p, vector<WALL> &w, vector<int> &vis) {
    
}

/*int slv(int cur, vector<POS> &p, vector<WALL> &w) {
    int ans = 0;
    int cx = p[cur].x, cy = p[cur].y;
    for (int i = 0; i < n; ++i) {
        if (i == cur) continue;
        int flag = 1;
        for (int j = 0; j < m; ++j) {
            if (banana({w[j]},{cx,cy,p[i].x,p[i].y})) flag = 0;
        }
        ans += flag;
    }
    return ans;
}*/

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    if (n > 500) return 0;
    vector<POS> p(n);
    for (auto& [x,y] : p) cin>>x>>y;
    cin>>m;
    if (m > 500) return 0;
    vector<WALL> w(m);
    vector<int> vis(m,0);
    for (auto& [sx,sy,tx,ty] : w) cin>>sx>>sy>>tx>>ty;
    for (int i = 0; i < n; ++i) {
        cout<<solve(i,p,w,vis)<<endl;
    }
    return 0;
}
