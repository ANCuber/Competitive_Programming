#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll tri[3];
    for (int i = 0; i < 3; ++i) cin>>tri[i];
    sort(tri,tri+3);
    if (tri[0]*tri[0]+tri[1]*tri[1] == tri[2]*tri[2]) {
        cout<<"yes\n";
    } else {
        cout<<"no\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    while(n--){
        solve();
    }
    return 0;
}