#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

vector<int> num, low, prt;
bitset<10005> ans;
int cnt, n, m;

void dfs(int cur, vector<vector<int> > &g) {
    num[cur] = low[cur] = ++cnt;
    int child = 0;
    for (auto i : g[cur]) {
        if (!num[i]) {
            child++;
            prt[i] = cur;
            dfs(i,g);
            low[cur] = min(low[i],low[cur]);

            if ((prt[cur] == -1 && child > 1) || (prt[cur] != -1 && low[i] >= num[cur])) {
                ans[cur] = 1;
            }
        } else if(i != prt[cur]){
            low[cur] = min(low[cur],num[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        ans.reset(); cnt=0;
        cin>>n>>m;
        vector<vector<int> > g(n+1);
        num.assign(n+1,0), low.assign(n+1,1e9), prt.assign(n+1,-1);
        int a, b;
        for (int i = 0; i < m; ++i) {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,g);
        cout<<ans.count()<<endl;
        if(!ans.count()) {cout<<0<<endl; continue;}
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (ans[i] && !flag) {
                cout<<i;
                flag = 1;
            } else if (ans[i]) {
                cout<<' '<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
