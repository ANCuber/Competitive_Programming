#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

int main() {
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector <vector <int> > graph(n);
        vector <int> indgr(n,n-1);
        for (int i = 0; i < m; ++i) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            indgr[a]--;
        }
        int ctrl = 0;
        priority_queue <int> start;
        for (int i = 0; i < n; ++i) {
            if (indgr[i] == 0) {
                ctrl = 1;
                start.push(i);
            }
        }
        if (!ctrl) {
            cout<<"QAQ\n";
            continue;
        }
        vector <int> ans;
        while (!start.empty()) {
            int cur = start.top();
            start.pop();
            for (int i = 0; i < n; ++i) {
                auto iter = find(graph[i].begin(),graph[i].end(),cur);
                if (iter != graph[i].end()) continue;
                indgr[i]--;
                graph[cur].push_back(i);
                if (!indgr[i]) start.push(i);
            }
            ans.push_back(cur);
        }
        if (ans.size() != n) {
            cout<<"QAQ\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}