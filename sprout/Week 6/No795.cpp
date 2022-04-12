#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Dot {
    long long x;
    long long y;
};

bool cmp_x (Dot a, Dot b){
    return a.x < b.x;
}
bool cmp_y (Dot a, Dot b){
    return a.y < b.y;
}

long long solve(int l, int r, vector <Dot> &dots) {
    if (r - l == 1) {
        long long xd = dots[r].x-dots[l].x;
        long long yd = dots[r].y-dots[l].y;
        return xd*xd+yd*yd;
    } else if (r - l == 2) {
        long long d = LONG_LONG_MAX;
        for (int i = l; i <= l+1; ++i) {
            for (int j = i+1; j <= l+2; ++j) {
                long long xd = dots[i].x-dots[j].x;
                long long yd = dots[i].y-dots[j].y;
                if (xd*xd+yd*yd < d) d = xd*xd+yd*yd;
            }
        }
        return d;
    }
    int mid = (l+r)>>1;
    long long min_c = min(solve(l,mid,dots),solve(mid+1,r,dots));
    long long min_dis = LONG_LONG_MAX;
    long long l_fund = dots[mid].x, l_horz = dots[mid].y;
    long long r_fund = dots[mid+1].x, r_horz = dots[mid+1].y;
    if (r_fund - l_fund >= min_c) return min_c;
    int r_range = r_fund-min_c;//***|
    int l_range = l_fund+min_c;// |***
    for (int i = l; i <= r; ++i) {
        if (dots[i].x >= r_range && dots[i].x <= r_fund) {
            long long xd = dots[i].x - dots[r].x;
            long long yd = dots[i].y - dots[r].y;
            min_dis = min(min_dis,xd*xd+yd*yd);
        }
        if (dots[i].x <= l_range && dots[i].x >= l_fund) {
            long long xd = dots[i].x - dots[l].x;
            long long yd = dots[i].y - dots[l].y;
            min_dis = min(min_dis,xd*xd+yd*yd);
        }
    }
    return min(min_c,min_dis);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Dot> dots(n);
    for (int i = 0; i < n; ++i) {
        cin>>dots[i].x>>dots[i].y;
    }
    sort(dots.begin(),dots.end(),cmp_x);
    cout<<solve(0,n-1,dots)<<endl;
    return 0;
}