#pragma GCC optimize("Ofast")
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
    if (s.size() == 1) {
        cout<<(s[0]-'0'+1)<<endl;
    } else {
        int ans = (int(s.size()-1))*10+(s[0]-'0'-1);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] > s[0]) {
                ans++;
                break;
            } else if (s[i] < s[0]) {
                break;
            } else if (i == s.size()-1) {
                ans++;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
