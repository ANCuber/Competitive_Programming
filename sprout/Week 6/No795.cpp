#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Point {
    long long x;
    long long y;
};

bool cmp_x (Point a, Point b){
    return a.x < b.x;
}
bool cmp_y (Point a, Point b){
    return a.y < b.y;
}

long long solve(int l, int r, vector <Point> &dots) {
    if (r == l) {
        return LONG_LONG_MAX;
    } else if (r-l == 1) {
        if (dots[l].y > dots[r].y) swap(dots[l],dots[r]);
        long long xd = dots[r].x-dots[l].x;
        long long yd = dots[r].y-dots[l].y;
        return xd*xd+yd*yd;
    }

    int mid = (l+r)>>1;
    long long min_c = min(solve(l,mid,dots),solve(mid+1,r,dots));
    long long min_dis = LONG_LONG_MAX;
    long long d = ceil(sqrt(min_c));
    if (min_c == 0) return min_c;
    long long fund = dots[mid].x;
    vector <Point> temp(r-l+1);
    merge(
        dots.begin()+l,dots.begin()+mid+1,
        dots.begin()+mid+1,dots.begin()+r+1,
        temp.begin(), cmp_y
    );
    int id = l;
    for (int i = 0; i < r-l+1; ++i) {
        dots[id++] = temp[i];
    }
    temp.clear();
    for (int i = l; i <= r; ++i) {
        if (abs(dots[i].x-fund) < d) {
            temp.push_back(dots[i]);
        }
    }
    int len = temp.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            long long xd = temp[i].x-temp[j].x;
            long long yd = temp[i].y-temp[j].y;
            min_dis = min(min_dis,xd*xd+yd*yd);
            if (temp[j].y-temp[i].y > d) break;
        }
    }

    return min(min_dis,min_c);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Point> dots(n);
    for (int i = 0; i < n; ++i) {
        cin>>dots[i].x>>dots[i].y;
    }
    if (n == 1) {
        cout<<0<<endl;
        return 0;
    }
    sort(dots.begin(),dots.end(),cmp_x);
    cout<<solve(0,n-1,dots)<<endl;
    return 0;
}