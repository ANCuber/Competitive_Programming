#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    while(n--) {
        ll tri[3];
        int i = 3;
        for (int i = 0; i < 3; ++i) {
            cin>>tri[i];
        }
        sort(tri,tri+3);
        if (tri[0]>0 && tri[1]>0 && tri[2]>0 && tri[0]*tri[0]+tri[1]*tri[1]==tri[2]*tri[2]) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}