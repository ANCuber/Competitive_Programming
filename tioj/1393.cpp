#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, ans;
bitset<10005> v;

void dfs(int fa, int cur, vector<vector<int> > &g) {
    for (auto& i : g[cur]) if (i!=fa) dfs(cur,i,g);
    if (!v[cur]) {
        ans++;
        v[fa] = 1;
        for (auto& i : g[fa]) v[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n) {
        ans = 0;
        vector<vector<int> > g(n+1);
        for (int i = 1; i < n; ++i) {
            int x, y; cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(0,1,g);
        cout<<ans<<endl;
    }
    return 0;
}
