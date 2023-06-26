#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        int n; cin>>n;
        string s, ans; cin>>s;
        for (int i = 0; i < s.size(); ++i) {
            char cur = s[i];
            ans = ans+cur;
            i++;
            while(s[i] != cur) {
                i++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
