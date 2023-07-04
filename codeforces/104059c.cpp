#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    set <int> s;
    char cmd;
    int a, b;
    while(q--) {
        cin>>cmd;
        if (cmd == '+') {
            cin>>a;
            s.erase(a);
        } else if (cmd == '-') {
            cin>>a;
            s.insert(a);
        } else {
            cin>>a>>b;
            if (a > b) swap(a,b);
            if (s.count(a) || s.count(b)) {
                cout<<"impossible"<<endl;
                continue;
            }
            auto iter = s.upper_bound(a);
            int k = *iter;
            if (iter == s.end()) k = 1e9;
            if (a == b || k > b || (*s.begin() > a && *s.rbegin() < b)) {
                cout<<"possible"<<endl;
            } else {
                cout<<"impossible"<<endl;
            }
        }
    }
    return 0;
}

