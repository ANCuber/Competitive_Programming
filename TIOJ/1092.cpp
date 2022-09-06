#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int n, e;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>e && (n+e)) {
        vector<vector<int> > g(n+1);
        vector<int> dg(n+1,0), lb(n+1,1);
        queue<int> q;
        int a, b;
        while(e--) {
            cin>>a>>b;
            g[b].push_back(a);
            dg[a]++;
        }
        string x; cin>>x;
        for (int i = 1; i <= n; ++i) {
            if (!dg[i]) {
                q.push(i);
                break;
            }
        }
        int cur;
        //lb[q.front()] = 1;
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            for (auto i : g[cur]) {
                if (lb[cur]) lb[i] = 0;
                dg[i]--;
                if (!dg[i]) {
                    q.push(i);
                }
            }
        }
        //for(int i=1;i<=n;i++) cout<<i<<" "<<lb[i]<<"\n";
        if (lb[cur]) {
            if (x[1] == 'i') {
                cout<<"Mimi"<<endl;
            } else {
                cout<<"Moumou"<<endl;
            }
        } else {
            if (x[1] == 'i') {
                cout<<"Moumou"<<endl;
            } else {
                cout<<"Mimi"<<endl;
            }
        }
    }
    
    return 0;
}
