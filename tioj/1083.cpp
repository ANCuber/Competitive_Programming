#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

string itos(int k) {
    string ans = "";
    while(k) {
        ans = char('0'+k%10)+ans;
        k /= 10;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> len(45,0);
    len[1] = 1;
    string str[2] = {"","1"};
    for (int i = 2; i < 43; ++i) {
        str[i&1] = "";
        int cnt = 0;
        char pre = '*';
        for (int j = 0; j < str[i&1^1].size(); ++j) {
            if (pre != str[i&1^1][j] && cnt) {
                str[i&1] += (itos(cnt)+pre);
                pre = str[i&1^1][j];
                cnt = 1;
            } else {
                cnt++;
                pre = str[i&1^1][j];
            }
        }
        str[i&1] += (itos(cnt)+pre);
        len[i] = str[i&1].size();
    }
    int n; 
    while(cin>>n && n) {
        cout<<len[n]<<' ';
        cout<<fixed<<setprecision(6)<<1.0*len[n-1]/len[n]<<'\n';
    }
    return 0;
}
