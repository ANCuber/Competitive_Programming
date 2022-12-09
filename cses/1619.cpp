#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

map<int,int> mp;
set<int> s;
int cnt = 0;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector< pii > v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].first>>v[i].second;
        s.insert(v[i].first), s.insert(v[i].second);
    }
    for (auto i : s) mp[i] = ++cnt;

    vector<int> p(cnt+5,0);
    for (auto [l,r] : v) {
        p[mp[l]]++;
        p[mp[r]]--;
    }
    int sum = 0, ans = 0;
    for (int i = 1; i < p.size(); ++i) {
        sum += p[i];
        ans = max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
