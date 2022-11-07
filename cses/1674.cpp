#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define eb emplace_back

int n, p;

int dfs(int cur, vector<vector<int> > &g, vector<int> &ans) {
    for (auto v : g[cur]) ans[cur] += dfs(v,g,ans);
    return ans[cur]+1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d",&n);
    vector<vector<int> > g(n+1);
    vector<int> ans(n+1,0);
    for (int i = 2; i <= n; ++i) {
        scanf("%d",&p);
        g[p].eb(i);
    }
    dfs(1,g,ans);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
