#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin>>s;
    int A = 0, B = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i&1) {
            A += (s[i]-'0');
        } else {
            B += (s[i]-'0');
        }
    }
    cout<<abs(A-B)<<'\n';
    return 0;
}
