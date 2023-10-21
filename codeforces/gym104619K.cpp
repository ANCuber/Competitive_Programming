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
    string s; cin>>s;    
    string t = "kick";
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i+j] != t[j]) break;
            if (j == 3) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
