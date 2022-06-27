#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define endl '\n'
#define ll long long

vector <int> h;

int dfs(int cur, int pre, vector<vector<int> > &graph) {
    int ret = 0;
    for (auto i : graph[cur]) {
        if (i != pre) ret = max(ret,dfs(i,cur,graph));
    }
    h[cur] = ret;
    return ret+1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > graph(n+1);
    h.resize(n+1,0);
    vector<int> in(n+1,0);
    for (int i = 1; i <= n; ++i) {
        int k; cin>>k;
        for(int j = 0; j < k; ++j) {
            int a; cin>>a;
            graph[i].push_back(a);
            in[a]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            cout<<i<<endl;
            dfs(i,-1,graph);
            break;
        }
    }
    ll ans = 0;
    for (auto i : h) ans += i;
    cout<<ans<<endl;
    
    return 0;
}