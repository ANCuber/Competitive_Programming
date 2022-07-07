#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string cmd;
    set <int> s;
    int x;
    while(cin>>cmd) {
        if (cmd[0] == 'e') break;
        cin>>x;
        if (cmd[0] == 'i') {
            s.insert(x);
        } else if (cmd[0] == 'r') {
            auto it = s.find(x);
            if (it != s.end()) s.erase(it);
        } else {
            if (x > s.size() || x <= 0) {
                cout<<"error\n";
                continue;
            }
            auto it = s.begin();
            for (int i = 0; i < x-1; ++i) {
                it++;
            }
            cout<<*it<<endl;
        }
    }
    return 0;
}
