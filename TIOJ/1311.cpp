#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int z, x1, x2, y1, y2;    
    while(cin>>z && z) {
        cin>>x1>>x2>>y1>>y2;
        for (int i = y1; i <= y2; ++i) {
            for (int j = x1; j <= x2; ++j) {
                if (__gcd(__gcd(i,j),z) == 1) cout<<'*';
                else cout<<'.';
            }
            cout<<endl;
        }
        cout<<"--"<<endl;
    }
    return 0;
}
