#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<string> splitLine(string s) {
    vector<string> ret;
    string tmp = "";
    s += ' ';
    for (auto &i : s) {
        if (i == ' ') {
            ret.push_back(tmp);
            tmp = "";
        } else {
            tmp += i;
        }
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        
        vector<string> cls = splitLine(s);
        vector<vector<string> > ans(2);
        bool nt = 0;
        int flg = 0;
        for (auto &i : cls) {
            if (i == "THEN") flg = 1;
            if (i == "IF" || i == "THEN") continue;
            
            if (i == "not") {
                nt = !nt;
            } else if (i == "and") {
                ans[flg].push_back("or");
            } else if (i == "or") {
                ans[flg].push_back("and");
            } else {
                if (!nt) ans[flg].push_back("not");
                ans[flg].push_back(i);
                nt = 0;
            }
        }
        
        cout << "IF";
        for (auto &i : ans[1]) cout << " " << i;
        cout << " THEN";
        for (auto &i : ans[0]) cout << " " << i;
    
        cout << '\n';
    }
    return 0;
}
