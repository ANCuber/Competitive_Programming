#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Dot {
    long long x;
    long long y;
    bool operator<(Dot b) {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};

long long min_d = 1e12;

void solve(int l, int r, vector <Dot> &dots) {
    if (l == r) return;
    int mid = (l+r)>>1;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Dot> dots(n);
    for (int i = 0; i < n; ++i) {
        cin>>dots[i].x>>dots[i].y;
    }
    sort(dots.begin(),dots.end());
    solve(0,n,dots);
    cout<<min_d<<endl;
    return 0;
}