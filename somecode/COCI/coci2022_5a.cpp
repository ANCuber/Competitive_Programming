#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    while(n--) {
        string s; cin>>s;
        s = '+'+s+"%";
        map<char,int> l[2];
        set<char> st;
        int cnt = 0, k = 0;
        char pre;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (s[i] == '-') k = 1;
                i += (1+(s[i] == '-'));
                if ('1' <= s[i] && s[i] <= '9') {
                    cnt = s[i]-'0';
                } else {
                    cnt = 1;
                    i--;
                }
            } else {
                st.insert(s[i]);
                if ('1' <= s[i+1] && s[i+1] <= '9') {
                    l[k][s[i]] += cnt*(s[i+1]-'0');
                    i++;
                } else {
                    l[k][s[i]] += cnt;
                }
            }
        }
        int flag = 0;
        for (auto c : st) {
            //cout<<c<<' '<<l[0][c]<<' '<<l[1][c]<<endl;
            if (l[0][c] != l[1][c]) {
                flag = 1;
                break;
            }
        }
        if (flag) cout<<"NE"<<endl;
        else cout<<"DA"<<endl;
    }
    return 0;
}
