#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector<int> dp;
vector<int> vis;

int dfs(vector<vector<int> > &g, int cur) {
    vis[cur] = 1;
    priority_queue <int> pq;
    for (auto i : g[cur]) {
        if (!vis[i]) {
            pq.push(dfs(g,i));
        }
    }
    if (pq.size() > 1) {
        dp[cur] = pq.top();
        pq.pop();
        dp[cur] += pq.top();
        return dp[cur]-pq.top()+1;
    } else if (pq.size() == 1) {
        dp[cur] = pq.top();
        return dp[cur]+1;
    } else {
        return 1;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int p;
    vector<vector<int> > g(n);
    vis.resize(n,0);
    dp.resize(n,0);
    for (int i = 0; i < n; ++i) {
        while(cin>>p && p != -1) {
            g[i].push_back(p);
        }
    }
    dfs(g,0);
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}
