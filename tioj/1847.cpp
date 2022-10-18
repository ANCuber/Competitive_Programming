#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

ll ans = 0;
int D;

void bfs(int arr[], vector<vector<int> > &g, vector<int> &v) {
    queue< pii , list< pii > > q;
    q.push({0,0});
    v[0] = 1;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        ans += arr[cur.first];
        if (cur.second == D) continue;
        for (auto i : g[cur.first]) {
            if (!v[i]) {
                q.push({i,cur.second+1});
                v[i] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; ++i) cin>>arr[i];
    vector<vector<int> > g(n);
    vector<int> v(n,0);
    int a, b;
    while(m--) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>D;
    bfs(arr,g,v);
    cout<<ans<<endl;
    return 0;
}
