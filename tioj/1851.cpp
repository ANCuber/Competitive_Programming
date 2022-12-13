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
    ll n;
    while(cin>>n && n) {
        ll sq = sqrt(n);
        if (sq*sq == n) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
