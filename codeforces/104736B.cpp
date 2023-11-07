#pragma GCC optimize("Ofast","unroll-loops")
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
    map<int,int> mp;
    for (int i = 0; i < 3*n; ++i) {
        int x; cin>>x;
        mp[x]++;
    }
    int flg = 1;
    for (auto [i,j] : mp) {
        if (j%3) flg = 0;
    }
    if (flg) cout<<"N\n";
    else cout<<"Y\n";
    return 0;
}
