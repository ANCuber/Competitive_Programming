#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;    
    sort(s.begin(),s.end());
    deque<char> dq, mid;
    vector<int> cnt(30,0);
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]-'A']++;
    }
    int flag = 0;
    for (int i = 0; i < 28; ++i) {
        flag += (cnt[i]&1);
    }
    if ((s.size()%2 == 0 && flag) || (s.size()%2 == 1 && flag >= 2)) {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    for (int i = 0; i < 28; ++i) {
        if (cnt[i]&1) {
            for (int j = 0; j < cnt[i]; ++j) mid.pb(char(i+'A'));
        } else {
            for (int j = 0; j < cnt[i]/2; ++j) dq.pb(char(i+'A'));
        }
    }
    for (int i = 0; i < dq.size(); ++i) cout<<dq[i];
    for (int i = 0; i < mid.size(); ++i) cout<<mid[i];
    for (int i = dq.size()-1; i >= 0; --i) cout<<dq[i];
    cout<<endl;
    return 0;
}
