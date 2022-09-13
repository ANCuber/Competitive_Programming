#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

map <char,int> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mp['S'] = 0;
    mp['D'] = 1;
    mp['T'] = 2;
    mp['H'] = 3;
    string rec;
    while(cin>>rec && rec != "x") {
        int ans[2] = {0,0};
        int ctrl = 0;
        int out = 0;
        deque <int> dq;
        for (int i = 0; i < 3; ++i) dq.push_back(0);
        for (int i = 0; i < rec.size(); ++i) {
            if (rec[i] == 'K' || rec[i] == 'O') {
                out++;
            } else if (rec[i] == 'W') {
                int sz = dq.size();
                if (dq[sz-1] == 1) {
                    if (dq[sz-2] == 1) {
                        if (dq[sz-3] == 1) {
                            ans[ctrl]++;
                        } else {
                            dq[sz-3] = 1;
                        }
                    } else {
                        dq[sz-2] = 1;
                    }
                } else {
                    dq[sz-1] = 1;
                }
            } else {
                dq.push_back(1);
                for (int j = 0; j < mp[rec[i]]; ++j) {
                    dq.push_back(0);
                }
            }
            while(dq.size() > 3) {
                ans[ctrl] += dq.front();
                dq.pop_front();
            }
            if (out == 3) {
                out = 0;
                ctrl = 1-ctrl;
                dq.clear();
                for (int i = 0; i < 3; ++i) dq.push_back(0);
            }
        }
        cout<<ans[0]<<' '<<ans[1]<<endl;
    }
    return 0;
}
