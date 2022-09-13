#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll dfs(vector<vector<int> > &graph, int cur, vector<int> &ans,vector<int> &vis) {
    vis[cur] = 1;
    priority_queue <ll> arr;
    ll maxn = 0;
    for (auto i : graph[cur]) {
        if (!vis[i]) {
            ll x = dfs(graph,i,ans,vis);
            arr.push(x);
            maxn = max(maxn,x);
        }
    }
    if (arr.size() >= 2) {
        ans[cur] = arr.top();
        arr.pop();
        ans[cur] += arr.top();
    } else {
        if (arr.empty()) {
            ans[cur] = 0;
        } else {
            ans[cur] = arr.top();
        }
    }
    return maxn+1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        if (cin.fail()) break;
        vector<vector<int> > graph(n);
        vector<int> ans(n,-1);
        vector<int> vis(n,0);
        for (int i = 0; i < n-1; ++i) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(graph,0,ans,vis);
        cout<<*max_element(ans.begin(),ans.end())<<endl;;
    }
    return 0;
}