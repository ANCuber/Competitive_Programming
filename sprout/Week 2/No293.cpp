#include <bits/stdc++.h>
using namespace std;

int n;

int dfs(int now, int last, vector<vector<int> > &graph, vector<bool> &travelled, vector<int> &maxsub) {
    travelled[now] = 1;
    int maxnum = 0;
    int all = 0;
    int subtree;
    for (int i = 0; i < graph[now].size(); ++i) {
        if (!travelled[graph[now][i]]) {
            subtree = dfs(graph[now][i], now, graph, travelled, maxsub);
            all += subtree;
            if (subtree>maxnum) maxnum = subtree;
        }
    }
    if (maxnum < (n-all-1)) maxnum = (n-all-1);
    maxsub[now] = maxnum;
    return all+1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    for (int l = 1; l <= t; ++l) {
        cin>>n;
        vector <vector<int> > graph(n+5);
        vector <int> maxsub(n+5,0);
        vector <bool> travelled(n+5,0);
        for (int i = 0; i < n-1; ++i) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0,-1,graph,travelled,maxsub);
        int min = 1e9;
        int minid;
        for (int i = 0; i < n; ++i) {
            if (maxsub[i] < min) {
                min = maxsub[i];
                minid = i;
            }
        } 
        cout<<minid<<'\n';
    }
    return 0;
} 