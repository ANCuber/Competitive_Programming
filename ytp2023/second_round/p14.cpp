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
    string s; cin>>s;    
    int q, x; cin>>q;
    for (int i = 0; i < q; ++i) cin>>x;
    int tmp = s.size();
    if (tmp <= 2) cout<<1<<endl;
    else cout<<(tmp-3)/2+2<<endl;
    
    return 0;
}
