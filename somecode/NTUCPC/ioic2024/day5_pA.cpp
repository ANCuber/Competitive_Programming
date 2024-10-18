#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin>>N;    
    vector<int> a(N);
    map<int,int> mp;
    int flag = 0, mx = 0;
    for (auto &i : a) {
        cin>>i;
        mp[i]++;
        mx = max(mx,i);
        if (mp[i] > 2) flag = 1;
    }
    if (flag || mp[mx] >= 2) {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    return 0;
}
