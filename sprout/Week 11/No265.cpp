#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <int> border;

void LPS(string &p) {
    border.resize(p.size(),-1);
    for (int i = 1; i < p.size(); ++i) {
        int j = border[i-1];
        while (j >= 0 && (p[j+1] != p[i])) {
            j = border[j];
        }
        if (p[j+1] == p[i]) border[i] = ++j;
    }
}

void match(string &s, string &t, vector<int> &ans) {
    for (int i = -1, m = 0;m < t.size();++m) {
        while (i >= 0 && s[i+1] != t[m]) {
            i = border[i];
        }
        if (s[i+1] == t[m]) i++;
        
        if (i == s.size()-1) {
            ans.push_back(m-i);
            i = border[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, t;
    cin>>s>>t;
    LPS(s);
    vector <int> ans;
    match(s,t,ans);
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}