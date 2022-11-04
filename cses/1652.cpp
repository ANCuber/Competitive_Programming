#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BBIT {
    vector<vector<int> > a;
    int sz;
    void init(int _n) {
        sz = _n;
        a.assign(sz+5,vector<int>(sz+5,0));
    }
    void upd(int x, int y, int v) {
        int ty;
        while(x <= sz) {
            ty = y;
            while(ty <= sz) {
                a[x][ty] += v;
                ty += ty&-ty;
            }
            x += x&-x;
        }
    }
    int sum(int x, int y) {
        int ret = 0, ty;
        while(x > 0) {
            ty = y;
            while(ty > 0) {
                ret += a[x][ty];
                ty -= ty&-ty;
            }
            x -= x&-x;
        }
        return ret;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, y1, x1, y2, x2, ans;
    string x;
    cin>>n>>q;
    bit.init(n);
    for (int i = 1; i <= n; ++i) {
        cin>>x;
        for (int j = 0; j < n; ++j) {
            if(x[j] == '*') bit.upd(i,j+1,1);
        }
    }
    while(q--) {
        cin>>x1>>y1>>x2>>y2;
        ans = bit.sum(x2,y2)-bit.sum(x2,y1-1)-bit.sum(x1-1,y2)+bit.sum(x1-1,y1-1);
        printf("%d\n",ans);
    }
    return 0;
}
