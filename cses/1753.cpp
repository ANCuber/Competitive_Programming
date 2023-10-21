#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b; cin>>a>>b;
    string s = b+'$'+a;
    vector<int> z(s.size(),0);
    int ans = 0;
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        if (i <= r) z[i] = min(z[i-l],r-i+1);
        while(s[i+z[i]] == s[z[i]] && i+z[i] < s.size()) z[i]++;
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
        if (z[i] == b.size()) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
