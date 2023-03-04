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
    int n, k; cin>>n>>k;    
    int ans = 0;
    int l = 1;
    map<int,int> mp;
    set<int> s;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        s.insert(a[i]);
        mp[a[i]]++;
        while(s.size() > k) {
            mp[a[l]]--;
            if (!mp[a[l]]) s.erase(a[l]);
            l++;
        }
        ans += i-l+1;
    }
    cout<<ans<<endl;
    return 0;
}
