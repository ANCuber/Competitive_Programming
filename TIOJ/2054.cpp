#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

struct City{
    int x, y;
};

bool cmpx(const City &a, const City &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(const City &a, const City &b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ln, w;
    cin>>n>>ln>>w;
    vector <City> px(n), py;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>px[i].x>>px[i].y;
        }
    }
    py = px;
    sort(px.begin(),px.end(),cmpx);
    sort(py.begin(),py,end(),cmpy)
    int d, u, l, r;

    for (int i = 0; i < n; ++i) {
        l = px[i].x;
        r = l+w;
        for (int j = 0; j < n; ++j) {
            
        }
    }

    return 0;
}
