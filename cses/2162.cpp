#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    auto iter = s.begin();
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' '; 
        iter++;
        if (iter == s.end()) iter = s.begin();
        cout<<*iter;
        iter = s.erase(iter);
        if (iter == s.end()) iter = s.begin();
    }
    return 0;
}
