#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int,int>

struct Rec{
    int L, D, R;
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin>>s;
    stack<Rec> stk;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'T') {
            int tmp = (s[++i]-'0')*10+(s[++i]-'0');
            stk.push({tmp,0,tmp});
        } else if (s[i] == 'L') {
            int tmp = (s[++i]-'0');
            stk.push({-1,tmp,-1});
        } else {
            Rec cur = stk.top();
            stk.pop();
            while(stk.top().L > 0) {
                cur.D += abs(stk.top().R-cur.L)+stk.top().D;
                cur.L = stk.top().L;
                stk.pop();
            }
            cur.D *= (stk.top().D);
            cur.D += (stk.top().D-1)*abs(cur.L-cur.R);
            stk.pop();
            stk.push(cur);
        }
    }
    Rec pos = stk.top();
    stk.pop();
    while(!stk.empty()) {
        pos.D += abs(pos.L-stk.top().R)+stk.top().D;
        pos.L = stk.top().L;
        stk.pop();
    }
    cout<<pos.D<<'\n';
    return 0;
}
