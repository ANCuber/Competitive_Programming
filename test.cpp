#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void add1(int x, int y) {
    x += 1;
    y += 1;
}

void add2(int &x, int &y) {
    x += 1;
    y += 1;
}

void add3(int x[3]) {
    for (int i = 0; i < 3; ++i) x[i]++;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin>>a>>b;
    int c[3] = {1,2,3};
    add1(a,b); cout<<a<<' '<<b<<endl;
    add2(a,b); cout<<a<<' '<<b<<endl;
    add3(c); cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<endl;
    return 0;
}
