#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int tag = 1;

void dfs(vector<vector<int> > &g, vector<int> &od, int cur) {
    od[cur] = tag++;
    for (auto i : g[cur]) {
        if (!od[i]) dfs(g,od,i);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int k, v;
    vector<vector<int> > g(n+1);
    vector<int> od(n+1,0);
    vector<int> in(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>k;
        while(k--) {
            cin>>v;
            g[i].push_back(v);
            in[v]++;
        }
    }
    int s;
    for (int i = 1; i <= n; ++i) if(!in[i]) s = i;
    dfs(g,od,s);
    for (int i = 1; i <= n; ++i) {
        cout<<od[i]<<endl;
    }
    return 0;
}
