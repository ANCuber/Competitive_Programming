#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    int a, b;
    vector<vector<int> > g(n+1);
    for (int i = 0; i < n-1; ++i) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s, t, k;
    while(q--) {
        cin>>s>>t>>k;
        
    }
}
