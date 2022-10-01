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

int n;
vector<int> a;
bitset<35000> v;

void dfs(int fa, int cur, vector<vector<int> > &g, int flag) {
    a[cur] = flag;
    for (auto i : g[cur]) {
        if (i!=fa) dfs(cur,i,g,!flag);
    }
}

bool match(int cur, vector<vector<int> > &g, vector<int> &p) {
    for (auto i : g[cur]) {
        if (!v[i]) {
            v[i] = 1;
            if (!p[i] || match(p[i],g,p)) {
                p[i] = cur;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    if (n == 1) {
        cout<<1<<endl;
        return 0;
    }
    a.assign(n+1,-1);
    vector<vector<int> > g(n+1);
    vector<int> p(n+1,0);
    for (int i = 1; i < n; ++i) {
        int u, k; cin>>k;
        while(k--) {
            cin>>u;
            g[i].pb(++u);
            g[u].pb(i);
        }
    }
    dfs(0,1,g,0);
        
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            v.reset();
            if (match(i,g,p)) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

