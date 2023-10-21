#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> KMP(string &s) {
    vector<int> f(s.size(),0);
    for (int i = 1; i < s.size(); ++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if (s[i] == s[j]) f[i] = j+1;
    }
    return f;
}

vector<int> Z_alg(string &s) {
    vector<int> z(s.size(),0);
    for (int i = 1, l = 0, r = 1; i < s.size(); ++i) {
        if (i < r) z[i] = min(z[i-l],r-i);
        while(s[z[i]] == s[i+z[i]] && i+z[i] < s.size()) z[i]++;
        if (r < i+z[i]) l = i, r = i+z[i];
    }
    return z;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;    
    vector<int> pi = KMP(s), z = Z_alg(s);
    for (int i = 0; i < s.size(); ++i) {
        if (i) cout<<' ';
        cout<<z[i];
    }
    cout<<endl;
    for (int i = 0; i < s.size(); ++i) {
        if (i) cout<<' ';
        cout<<pi[i];
    }
    cout<<endl;
    return 0;
}
