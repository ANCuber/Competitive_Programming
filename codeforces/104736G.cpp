#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Sol{
    int m, k, l, r;
};

inline int D(int a, int b, int m) {
    return -m*a+b;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int x, y, d;
    cin>>x>>y>>d;
    vector<Sol> s(4);
    vector<vector<int> > arr(4,vector<int>(40005,0));
    vector<int> bnd(4), cnt(4,1);
    s[0] = {+1,D(x+d,y,1),x,x+d};
    s[1] = {-1,D(x+d,y,-1),x,x+d};
    s[2] = {+1,D(x-d,y,1),x-d,x};
    s[3] = {-1,D(x-d,y,-1),x-d,x};
    for (int i = 0; i < 4; ++i) {
        bnd[i] = {s[i].l,s[i].r};
    }
    for (int i = 2; i <= n; ++i) {
        cin>>x>>y>>d;
        vector<Sol> c(4);
        c[0] = {+1,D(x+d,y,1),x,x+d};
        c[1] = {-1,D(x+d,y,-1),x,x+d};
        c[2] = {+1,D(x-d,y,1),x-d,x};
        c[3] = {-1,D(x-d,y,-1),x-d,x};
        for (int j = 0; j < 4; ++j) {
            for (int h = 0; h < 4; ++h) {
                if (s[j].m == c[h].m && s[j].k == s[h].k) {
                    bnd[j].first = max(bnd[j].first,c[h].l);
                    bnd[j].second = min(bnd[j].second,c[h].r);
                    cnt[j]++;
                } else if (s[j].m != c[h].m) {
                    if ((s[j].k+c[h].k)%2) continue;
                    int X, Y;
                    if (s[j].m > 0) {
                        X = (c[h].k-s[j].k)/2;
                        Y = (c[h].k+s[j].k)/2;
                    } else {
                        X = (-c[h].k+s[j].k)/2;
                        Y = (c[h].k+s[j].k)/2;
                    }
                    int L = max(s[j].l,c[h].l), R = min(s[j].r,c[h].r);
                    if (L <= R && X >= L && X <= R) {
                        arr[j][X]++;
                    }
                }
            }
        }
    }
    vector<pii> ans;
    for (int i = 0; i < 4; ++i) {
        for (int j = bnd[i].first; j <= bnd[i].second; ++i) {
            if (arr[i][j]+cnt[i] == n) ans.pb({j,});
        }
    }
    return 0;
}
