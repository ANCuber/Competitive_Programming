#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int s=0, m;
vector <int> ans;

void dfs(int p, map<int,multiset<int> > &g) {
    while(!g[p].empty()) {
        int nx = *g[p].begin();
        g[p].erase(g[p].find(nx));
        g[nx].erase(g[nx].find(p));
        dfs(nx,g);
    }
    ans.push_back(p);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>m && m) {
        int a, b;
        map <int,multiset<int> > g;
        vector<int> rc(501,0);
        ans.clear();
        while(m--) {
            cin>>a>>b;
            rc[a]++;
            rc[b]++;
            g[a].insert(b);
            g[b].insert(a);
        }
        for (int i = 1; i <= 500; ++i) {
            if (rc[i] % 2 == 1) {
                s = i;
                break;
            }
        }
        if (s == 0) s = g.begin()->first;
        dfs(s,g);
        reverse(ans.begin(),ans.end());
        for (auto i : ans) cout<<i<<endl;
        cout<<endl;
    }
    return 0;
}
