#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k, q, r, p;
    cin>>k>>q>>r;
    vector<string> s(q+5);
    cin>>s[0];
    for (int i = 1; i <= q; ++i) {
        s[i] = s[i-1];
        for (int j = 0; j < k; ++j) {
            cin>>p;
            s[i][p-1] = s[i-1][j];
        }
        //cout<<"No."<<i<<' '<<s[i]<<endl;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 1; j <= q; ++j) {
            cout<<s[j][i];
        }
        cout<<'\n';
    }
    return 0;
}
