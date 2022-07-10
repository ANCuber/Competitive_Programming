#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Point{
    int x;
    int y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i].x>>p[i].y;
    }
    return 0;
}
