#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector<int> a(n+2,0), x(n+2,0);
    a[n+1] = n+1;
    for (int i = 1; i <= n; ++i) {
        cin>>x[i];
        a[x[i]] = i;
    }
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < a[i-1]) cnt++;
    }
    while(q--) {
        int u, v; cin>>u>>v;
        swap(x[u],x[v]);
        int tu = u, tv = v;
        u = x[tv], v = x[tu];
        if (u > v) swap(u,v);
        int cur = 0, tmp = 0, c = (abs(u-v)==1);
        if (c) {
            
        }
        if (a[u] < a[u-1]) cur++;
        if (!c && a[u] > a[u+1]) cur++;
        if (a[v] < a[v-1]) cur++;
        if (a[v] > a[v+1]) cur++;
        swap(a[u],a[v]);
        if (a[u] < a[u-1]) tmp++;
        if (!c && a[u] > a[u+1]) tmp++;
        if (a[v] < a[v-1]) tmp++;
        if (a[v] > a[v+1]) tmp++;
        cnt = cnt-cur+tmp;
        cout<<cnt<<endl;
    }
    return 0;
}
