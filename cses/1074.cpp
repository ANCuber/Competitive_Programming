#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> p(n);
    for (auto& i : p) cin>>i;
    sort(p.begin(),p.end());
    int cnt = 0;
    for (auto i : p) cnt += abs(i-p[n>>1]);
    cout<<cnt<<endl;
    return 0;
}
