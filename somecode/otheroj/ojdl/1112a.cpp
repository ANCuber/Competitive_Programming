#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int unsigned long long

map <string,int> mp;
vector<string> s(500005);
int cnt = 0;
int base = 1;

int ans, ed;

void dfs(int fa, int cur, int val, vector<vector<int> > &g) {
    if (cur == ed) {
        ans = (val|(base<<mp[s[cur]]));
    }
    for (auto v : g[cur]) {
        if (v != fa) {
            dfs(cur,v,val|(base<<mp[s[cur]]),g);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, K; cin>>n>>K;    
    if (n > 1005) return 0;
    vector<vector<int> > g(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>s[i];
        if (!mp.count(s[i])) mp[s[i]] = cnt++;
    }
    int u, v;
    for (int i = 1; i <= n-1; ++i) {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int t, q, st, p, k; cin>>q;
    string x;
    while(q--) {
        cin>>t;
        if (t == 1) {
            cin>>st>>ed>>k;
            int tar = 0, flag = 0;
            for (int i = 0; i < k; ++i) {
                cin>>x;
                if (flag) continue;
                if (!mp.count(x)) {
                    cout<<"NO\n";
                    flag = 1;
                }
                tar |= (base<<mp[x]);
            }
            dfs(-1,st,0,g);
            if (tar == (ans&tar)) cout<<"YES\n";
            else cout<<"NO\n";
        } else {
            cin>>p>>x;
            s[p] = x;
            if (!mp.count(x)) mp[x] = cnt++;
        }
    }
    return 0;
}
