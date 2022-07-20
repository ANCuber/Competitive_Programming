#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

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
}
