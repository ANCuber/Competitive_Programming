#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<ll> s(n+2), t(n+2), tg(n+2,0);
    for (int i = 1; i <= n; ++i) cin>>s[i];
    for (int i = 1; i <= n; ++i) cin>>t[i];
    deque<int> fight(n+1);
    queue<int> won, lost;
    for (int i = 1; i <= n; ++i) {
        int idx; cin>>idx;
        fight[idx] = i;
    }
    fight.pop_front();
    while(fight.size() > 1) {
        for (int i = 1; i <= n; ++i) cout<<s[i]<<' '; cout<<endl;
        for (int i = 1; i <= n; ++i) cout<<t[i]<<' '; cout<<endl;

        while(fight.size() >= 2) {
            int u = fight[0], v = fight[1];
            fight.pop_front(), fight.pop_front();
            //cout<<"R:"<<s[u]*t[u]<<' '<<s[v]*t[v]<<endl;
            if (s[u]*t[u] < s[v]*t[v]) swap(u,v);
            won.push(u);
            if (++tg[v] < m) lost.push(v);
            ll ns = s[u]+s[v]*t[v]/(2*t[u]), nt = t[u]+s[v]*t[v]/(2*s[u]);
            s[u] = ns, t[u] = nt;
            s[v] += s[v]/2, t[v] += t[v]/2;
        }
        if (!fight.empty()) {
            won.push(fight[0]);
            fight.pop_front();
        }
        while(!won.empty()) {
            fight.push_back(won.front());
            won.pop();
        }
        while(!lost.empty()) {
            fight.push_back(lost.front());
            lost.pop();
        }
        for (int i = 1; i <= n; ++i) cout<<tg[i]<<' '; cout<<endl;

    }
    cout<<fight[0]<<'\n';
    return 0;
}
