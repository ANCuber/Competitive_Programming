#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int ans[3] = {0,0,0};//left, right, back

struct Pt{
    ll x, y;
};

ll operator^(const Pt &p1,const Pt &p2) {
    return p1.x*p2.y-p1.y*p2.x;
}

ll operator*(const Pt &p1,const Pt &p2) {
    return p1.x*p2.x+p1.y*p2.y;
}

Pt operator-(const Pt &p1,const Pt &p2) {
    Pt ret;
    ret.x = p1.x-p2.x;
    ret.y = p1.y-p2.y;
    return ret;
}

void judge(Pt &o, Pt &a, Pt &b) {
    ll cross = (o-a)^(b-o);
    ll dot = (o-a)*(b-o);
    if (!cross) {
        if (dot < 0) {
            ans[2]++;
            //cout<<2;
        }
    } else if (cross>0) {
        ans[0]++;
        //cout<<0;
    } else {
        ans[1]++;
        //cout<<1;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Pt> point(n);
    for (int i = 0; i < n; ++i) {
        cin>>point[i].x>>point[i].y;
    }
    if (n == 1 || n == 2) {
        cout<<0<<' '<<0<<' '<<0<<endl;
        return 0;
    }
    for (int i = 1; i < n-1; ++i) {
        judge(point[i],point[i-1],point[i+1]);
    }
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
    return 0;
}