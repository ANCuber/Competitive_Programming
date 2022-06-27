#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        int v = n;
        vector <vector<int> > graph(n);
        vector <int> indgr(n,0);
        for (int i = 0; i < m; ++i) {
            int a, b; cin>>a>>b;
            graph[a].push_back(b);
            indgr[b]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            if (!indgr[i]) pq.push(i);
        }
        vector <int> ans;
        vector <int> vis(n,0);
        while(!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            vis[cur] = 1;
            //cout<<"cur#"<<cur<<endl;
            ans.push_back(cur);
            for (auto i : graph[cur]) {
                if (!vis[i] && !(--indgr[i])) {
                    pq.push(i);
                    //cout<<"push#"<<i<<endl;
                }
            }
        }
        if (ans.size() < n) {
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