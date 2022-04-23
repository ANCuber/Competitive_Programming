#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector <vector<int> > tree;
vector <int> c;

int dfs(vector <int> ans, int last, int now, int fvalue) {
    int maxvalue = -1;
    for (int i = 0; i < tree[now].size(); ++i) {
        if (tree[now][i] == last) continue;
        int x = dfs(ans,now,tree[now][i],fvalue);
    }

}

int main() {
    int n, q; cin>>n>>q;
    tree.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    vector <int> ans(n,-1);
    dfs(ans,-1,0,c[0]);
    for (int i = 0; i < q; ++i) {
        int r; cin>>r;
        cout<<ans[r-1]<<endl;
    }
}