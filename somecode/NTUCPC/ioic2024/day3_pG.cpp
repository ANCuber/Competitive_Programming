#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> vis(2005,0), p(2005,-1), tmp;

bool dfs(int u, vector<vector<int> > &g) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (p[v] == -1 || (!vis[p[v]] && dfs(p[v],g))) {
            p[v] = u;
            return 1;
        }
    }
    return 0;
}

int H(int K, vector<vector<int> > &g) {
    int ans = 0;
    for (int i = 1; i <= K; ++i) {
        fill(vis.begin(),vis.end(),0);
        ans += dfs(i,g);
    }
    return ans;
}

void DFS(int u, vector<vector<int> > &nw) {
    tmp.pb(u);
    for (auto v : nw[u]) {
        DFS(v,nw);
    }
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K; cin>>N>>K;    
    vector<vector<int> > g(K*2+5), nw(K*2+5);
    for (int i = 1; i <= N; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b+K);
        g[b+K].pb(a);
    }
    H(K,g);//match
    
    vector<int> A(1005,0);
    for (int i = 1; i <= K; ++i) {
        if (p[i+K] != -1) {
            //cout<<"match:"<<p[i+K]<<' '<<i<<endl;
            A[p[i+K]] = i+K;
        } 
    }
    for (int i = 1; i <= K; ++i) {
        for (auto v : g[i]) {
            if (v == A[i]) nw[v].pb(i);
            else nw[i].pb(v);
            //cout<<i<<' '<<A[i]-K<<endl;
        }
    }
    for (int i = 1; i <= K; ++i) if (!A[i]) DFS(i,nw);
    //for (auto i : tmp) cout<<i<<' '; cout<<endl;
    vector<int> aa, bb;
    vector<int> use(1005,1), ub(1005,0);
    for (auto i : tmp) {
        if (i <= K) {
            use[i] = 0;
        } else {
            ub[i-K] = 1;
        }
    }
    for (int i = 1; i <= K; ++i) if (use[i]) aa.pb(i);
    for (int i = 1; i <= K; ++i) if (ub[i]) bb.pb(i);
    cout<<aa.size()<<' '<<bb.size()<<endl;
    for (int i = 0; i < aa.size(); ++i) {
        if (i) cout<<' ';
        cout<<aa[i];
    }
    cout<<endl;
    for (int i = 0; i < bb.size(); ++i) {
        if (i) cout<<' ';
        cout<<bb[i];
    }
    cout<<endl;
    return 0;
}
