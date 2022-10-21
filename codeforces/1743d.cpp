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
    int n; cin>>n;    
    string s; cin>>s;
    int st = 0;
    for (; st < n; ++st) {
        if (s[st] == '1') break;
    }
    if (st == n) {
        cout<<s<<endl;
        return 0;
    }
    int c = st;
    for (; c < n; ++c) {
        if (s[c] == '0') break;
    }
    string cur = s;
    for (int j = st; j < n; ++j) {
        for (int i = )
    }
    return 0;
}
