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
    vector< pii > a(n);
    set<int> s;
    for (auto&[l,r] : a) {
        cin>>l>>r;
        s.insert(l), s.insert(r);
    }
    int c = 0;
    map<int,int> mp;
    for (auto i : s) mp[i] = ++c;
    for (auto&[l,r] : a) {
        l = mp[l];
        r = mp[r];
    }
    vector<int> cnt(c+5,0);
    for (auto [l,r] : a) {
        cnt[l]++;
        cnt[r+1]--;
    }
    for (int i = 1; i <= c; ++i) cnt[i] += cnt[i-1];
    int ans = *max_element(cnt.begin(),cnt.end());
    cout<<ans<<endl;
    
    return 0;
}
