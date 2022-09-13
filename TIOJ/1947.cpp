#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int n;
pii ans = {-1,1e8};

int dfs(int pre, int cur, vector<vector<int> > &g) {
    int sum = 1, mx = 0, rs;
    for (auto i : g[cur]) {
        if (i != pre) {
            rs = dfs(cur,i,g);
            sum += rs;
            mx = max(mx,rs);
        }
    }
    mx = max(mx,n-sum);
    if (mx < ans.second) {
        ans.first = cur;
        ans.second = mx;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;    
    vector<vector<int> > g(n);
    int u, v;
    for (int i = 0; i < n-1; ++i) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(-1,0,g);
    cout<<ans.second<<endl;
    return 0;
}
