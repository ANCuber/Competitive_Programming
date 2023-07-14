#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int prime[25] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};

vector<int> tmp;

void dfs(vector<bool> &vis, int cur, int n, int k) {
    if (k == n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                set<int> s;
                for (int k = i; k <= j; ++k) s.insert(tmp[k]);
                int nw = 1;
                for (auto k : s) if (k != nw++) break;
                if (prime[nw]) cnt++;
            }
        }
        cout<<cnt<<":";
        for (int i = 1; i <= n; ++i) cout<<tmp[i]<<' '; 
        cout<<endl;
        return;
    }
    vis[cur] = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        tmp.pb(i);
        dfs(vis,i,n,k+1);
    }
    vis[cur] = 0;
    tmp.pop_back();
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    tmp.pb(0);
    while(t--) {
        int n; cin>>n;
        vector<bool> vis(n+1,0);
        dfs(vis,0,n,0);
    }
    return 0;
}
