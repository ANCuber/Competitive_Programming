#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

vector<int> v, num, low;
int cnt;

void dfs(int cur, int fa, vector<vector<int> > &g) {
    num[cur] = low[cur] = ++cnt;
    int child = 0;
    for (auto i : g[cur]) {
        if (!num[i]) {
            chlid++;
            dfs(i,cur,g);
        } else if(i != fa){
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        v.clear(); cnt=0;
        cin>>n>>m;
        vector<vector<int> > g(n+1);
        num.assign(n+1,0), low.assign(n+1,1e9);
        int a, b;
        for (int i = 0; i < m; ++i) {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,0,g);
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;
        for (int i = 0; i < v.size(); ++i) {
            if (i) cout<<' ';
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}
