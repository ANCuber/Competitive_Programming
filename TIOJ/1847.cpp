#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

ll ans = 0;

void dfs(int cur, int d, int arr[], vector<vector<int> > &g, vector<int> &v) {
    
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
    dfs(0,0,arr,g,v);
    cout<<ans<<endl;
    return 0;
}
