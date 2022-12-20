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
    int n, x; cin>>n>>x;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin>>p[i];
    sort(p.begin(),p.end(),greater<int>());
    multiset<int> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto iter = s.lower_bound(p[i]);
        if (iter == s.end()) {
            cnt++;
            s.insert(x-p[i]);
        } else {
            s.erase(iter);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
