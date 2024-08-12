#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll s2n(string x) {
    ll ret = 0;
    for (int i = 0; i < x.size(); ++i) {
        ret *= 10;
        ret += (x[i]-'0');
    }
    return ret;
}

void Solve(string s) {
    string t = s;
    bool flg = 0;
    //Greater
    for (int i = 0; i < s.size(); ++i) {
        if (flg) {
            t[i] = '1';
        } else {
            if ((s[i]-'0')%2 == 0) {
                t[i] = char(s[i]+1);
                flg = 1;
            } else {
                t[i] = s[i];
            }
        }
    }
    ll ans = s2n(t)-s2n(s);
    //Smaller
    flg = 0;
    t = s;
    for (int i = 0; i < s.size(); ++i) {
        if (flg) {
            t[i] = '9';
        } else {
            if (s[i] == '0') {
                int j = i-1;
                for (; j >= 0; --j) if (s[j] != '1') break;
                if (j < 0 && s[0] == '1') t[++j] = '0';
                else t[j] = char(s[j]-2);
                
                for (int k = j+1; k <= i; ++k) t[k] = '9';
                //09999999
                flg = 1;
            } else if ((s[i]-'0')%2 == 0) {
                t[i] = char(s[i]-1);
                flg = 1;
            } else {
                t[i] = s[i];
            }
        }
    }
    ans = min(ans,s2n(s)-s2n(t));
    cout<<ans<<'\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string S;
    while(cin>>S) Solve(S);
    return 0;
}
