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
    int n; cin>>n;    
    vector<string> S(n);
    for (int i = 0; i < n; ++i) cin>>S[i];
    multiset<char> s;
    int g; cin>>g;
    while(g--) {
        string t; cin>>t;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            string cur = "";
            for (int i = 0; i < 5; ++i) s.insert(S[0][i]);
            for (int j = 0; j < 5; ++j) {
                if (S[i][j] == S[0][j]) cur = cur+'*';
                else {
                    if (s.count(S[i][j])) cur = cur+'!';
                    else cur = cur+'X';
                }
                if (s.count(S[i][j])) s.erase(s.find(S[i][j]));
                
            }
            s.clear();
            if (cur == t) ans++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
