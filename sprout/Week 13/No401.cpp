#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'

struct Point{
    ll x, y;
};

ll operator^(const Point &p1, const Point &p2) {
    return p1.x*p2.y-p1.y*p2.x;
}

ll operator*(const Point &p1, const Point &p2) {
    return p1.x*p2.x+p1.y*p2.y;
}

Point operator-(const Point &p1, const Point &p2) {
    Point ret;
    ret.x = p1.x-p2.x;
    ret.y = p1.y-p2.y;
    return ret;
}

int ori(Point &o, Point &a, Point &b) {
    ll cross = (a-o)^(b-o);
    if (!cross) return 0;
    return cross > 0 ? 1 : -1;
}

bool inseg(Point &a, Point &b, Point &c) {
    if (ori(a,b,c) != 0) return 0;
    return (c-a)*(c-b) <= 0;
}

bool banana(Point &p1, Point &p2, Point &q1, Point &q2) {
    int a123 = ori(p1,p2,q1);
    int a124 = ori(p1,p2,q2);
    int a341 = ori(q1,q2,p1); 
    int a342 = ori(q1,q2,p2);
    if (a123 == 0 && a124 == 0) {
        return inseg(p1,p2,q1) || inseg(p1,p2,q2) 
        || inseg(q1,q2,p1) || inseg(q1,q2,p2);
    }
    return a123*a124 <= 0 && a341*a342 <= 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        Point p1,p2,q1,q2;
        cin>>p1.x>>p1.y>>p2.x>>p2.y>>q1.x>>q1.y>>q2.x>>q2.y;
        if (banana(p1,p2,q1,q2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}