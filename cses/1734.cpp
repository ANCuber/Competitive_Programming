#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;    
    int cnt = 0;
    vector<int> a(n+1);
    set<int> s;
    map<int,int> mp;
    vector<pii> q(n+1);
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (auto i : s) mp[i] = ++cnt;
    for (int i = 1; i <= N; ++i) a[i] = mp[a[i]];
    for (int i = 1; i <= Q; ++i) cin>>q[i].first>>q[i].second;
    sort(q.begin(),q.begin());
    
    
    
    return 0;
}
