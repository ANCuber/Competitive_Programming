#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

struct Pt{
    int x;
    int y;
    bool operator<(Pt b) {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};

vector <Pt> p;
vector <Pt> stk;

Pt operator-(const Pt &p1, const Pt &p2) {
    Pt ret;
    ret.x = p1.x-p2.x;
    ret.y = p1.y-p2.y;
    return ret;
}

int operator^(const Pt &p1, const Pt &p2) {
    return p1.x*p2.y-p1.y*p2.x;
}

int cross(Pt o, Pt a, Pt b) {
    return (a-o)^(b-o);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    p.resize(n);
    stk.resize(n+5);
    for (int i = 0; i < n; ++i) cin>>p[i].x>>p[i].y;
    sort(p.begin(),p.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while(ans >= 2 && cross(stk[ans-2],stk[ans-1],p[i]) <= 0) {
            ans--;
        }
        stk[ans++] = p[i];
    }
    for (int i = n-2, t = ans+1; i >= 0; --i) {
        while(ans >= t && cross(stk[ans-2],stk[ans-1],p[i]) <= 0) {
            ans--;
        }
        stk[ans++] = p[i];
    }
    cout<<--ans<<endl;
    return 0;
}
