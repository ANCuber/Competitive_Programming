#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int m; cin>>m;
    vector<string> s(m);
    unordered_set<string> st;
    for (auto &i : s) {
        cin>>i;
        st.insert(i);
    }
    int ans = 0;
    for (auto i : s) {
        int len = i.size();
        for (int j = 1; j*2 < len; ++j) {
            if (i.substr(0,j) == i.substr(len-j,j) && st.count(i.substr(j,len-j*2))) ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
