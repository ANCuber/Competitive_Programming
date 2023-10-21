#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> KMP(string &s) {
    vector<int> f(s.size());
    for (int i = 1; i < s.size(); ++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = j+1;
    }
    return f;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;  
    vector<int> f = KMP(s);
    int cur = f[s.size()-1];
    deque<int> ans;
    while(cur) {
        ans.push_front(cur);
        cur = f[cur-1];
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    } 
    cout<<endl;
    return 0;
}
