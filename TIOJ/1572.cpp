#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

struct Nd{
    int p;
    vector<int> cp;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, st, ed;
    cin>>n>>m>>st>>ed;
    vector<p_q<int,vector<int>,greater<int> > > g(n+1);
    int x, y;
    while(m--) {
        cin>>x>>y;
        g[x].push(y);
        g[y].push(x);
    }
    queue <Nd> q;
    vector<int> ori;
    vector<int> vis(n+1,0);
    vector<int> ans;
    q.push({st,ori});
    while(!q.empty()) {
        int curp = q.front().p;
        vector<int> path = q.front().cp;
        path.push_back(curp);
        if (curp == ed) {
            ans = path;
            break;
        }
        q.pop();
        while(!g[curp].empty()) {
            if (!vis[g[curp].top()]) {
                q.push({g[curp].top(),path});
            }
            g[curp].pop();
        }
    }
    cout<<ans.size()-2<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<'-';
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}
