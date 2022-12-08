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
    int n; cin>>n;    
    multiset<int> s;
    while(n--) {
        int x; cin>>x;
        auto iter = s.upper_bound(x);
        if (iter != s.end()) s.erase(iter);
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}
