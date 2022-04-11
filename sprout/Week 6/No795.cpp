#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Dot {
    int x;
    int y;
};

int min_d = 1e9;

void solve(int l, int r) {
    int mid = l+(r-l)/2;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Dot> dots(n);
    for (int i = 0; i < n; ++i) {
        cin>>dots[i].x>>dots[i].y;
    }
    solve(-1e9,1e9);
    cout<<min_d<<endl;
    return 0;
}