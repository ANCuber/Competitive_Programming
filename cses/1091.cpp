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
    int n, m; cin>>n>>m;    
    multiset <int> s;
    for (int i = 1; i <= n; ++i) {
        int h; cin>>h;
        s.insert(h);
    }
    for (int i = 1; i <= m; ++i) {
        int t; cin>>t;
        if (s.empty()) {
            cout<<-1<<endl;
            continue;
        }
        auto iter = s.lower_bound(t);
        if (*iter == *s.begin() && *iter > t) {
            cout<<-1<<endl;
        } else if (*iter == t){
            cout<<*iter<<endl;
            s.erase(iter);
        } else {
            iter--;
            cout<<*iter<<endl;
            s.erase(iter);
        }
    }
    return 0;
}
