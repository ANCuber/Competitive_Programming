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
    int n, m; cin>>n>>m;
    vector<vector<int> > g(n+1);
    while(m--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> pre(n+1,0);
    queue<int> q;
    q.push(1);
    pre[1] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i : g[cur]) {
            if (!pre[i]) {
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    if (pre[n]) {
        int u = n;
        vector<int> ans;
        while(u != pre[u]) {
            ans.pb(u);
            u = pre[u];
        }
        ans.pb(1);
        cout<<ans.size()<<endl;
        for (int i = ans.size()-1; i >= 0; --i) {
            cout<<ans[i];
            if (i) cout<<' ';
        }
        cout<<endl;
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
