#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void failure(vector<int> &b, string p) {
    for (int i = 1; i < p.size(); ++i) {
        int j = b[i-1];
        while(j >= 0 && p[i] != p[j+1]) {
            j = b[j];
        }
        if (p[i] == p[j+1]) b[i] = ++j;
    }
}

int KMP(vector<int> &b, string &t, string &p) {
    int ans = 0;
    for (int i = -1, m = 0; m < t.size();++m) {
        while(i >= 0 && p[i+1] != t[m]) {
            i = b[i];
        }
        if (p[i+1] == t[m]) i++;
        if (i == p.size()-1) {
            ans++;
            i = b[i];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int td; cin>>td;
    while(td--) {
        string t; cin>>t;
        int q; cin>>q;
        while(q--) {
            string p; cin>>p;
            vector <int> border(p.size(),-1);
            border[0] = -1;
            failure(border,p);
            cout<<KMP(border,t,p)<<endl;
        }       
    }
    return 0;
}