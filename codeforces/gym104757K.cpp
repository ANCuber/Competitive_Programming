#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Puzzle{
    string a, b; 
    int len;
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<string> s(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) cin>>s[i];
    map<tuple<string,string,int>,int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < s[i].size(); ++j) {
            string cur = s[i].substr(0,j-1)+"00"+s[i].substr(j-1+2,s[i].size()-(j));
            map<string,int> mp;
            for (int k = i+1; k < n; ++k) {
                if (s[k].size() != s[i].size()) continue;
                string tmp = s[k].substr(0,j-1)+"00"+s[k].substr(j-1+2,s[k].size()-(j));
                if (tmp == cur && s[i][j] != s[k][j] && s[i][j-1] != s[k][j-1]) {
                    mp[{s[i].substr(j-1,2),s[k].substr(j-1,2),s[i].size()}]++;
                    mp[{s[k].substr(j-1,2),s[i].substr(j-1,2),s[i].size()}]++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
