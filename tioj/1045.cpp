#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int n;

void Run() {
    unsigned int ans = 0;
    vector<vector<pii> > add(10005), del(10005);
    while(n--) {
        int l, r, t, b;
        cin>>l>>t>>r>>b;
        add[t+1].pb({l,r});
        del[b+1].pb({l,r});
    }
    
    
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n && n) Run();
    return 0;
}
