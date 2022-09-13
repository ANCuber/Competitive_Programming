#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int n;

void solve() {
    cin>>n;
    vector<vector<int> > g(n+1);
    vector<int> in(n+1,0);
    vector<int> d(n+1,0);
    vector<int> tm(n+1,0);
    int k, p;
    for (int i = 1; i <= n; ++i) {
        cin>>d[i]>>k;
        while(k--) {
            cin>>p;
            g[i].push_back(p);
            in[p]++;
        }
    }

    queue <int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.push(i);
            tm[i] = 0;
        }
    }    
    int ans = -1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (g[cur].empty()) {
            ans = max(ans,tm[cur]+d[cur]);
            continue;
        }
        for (auto i : g[cur]) {
            tm[i] = max(d[cur]+tm[cur],tm[i]);
            in[i]--;
            if (!in[i]) q.push(i);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
