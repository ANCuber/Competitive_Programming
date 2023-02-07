#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct DSU{
    vector<int> bs;
    void init(int _n) {
        bs.assign(_n+5,0);
        for (int i = 1; i <= _n; ++i) bs[i] = i;
    }
    int find(int p) {
        if (p == bs[p]) return p;
        return bs[p] = find(bs[p]);
    }
    void add(int a, int b) {
        int m = find(a), n = find(b);
        if (m == n) return;
        bs[m] = n;
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    dsu.init(n);
    vector<int> a(n+1);
    vector<vector<int> > x(1000005);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        for (int j = 1; j*j <= a[i]; ++j) {
            if (a[i]%j) continue;
            x[j].pb(i);
            if (j != a[i]/j) x[a[i]/j].pb(i);
        }
    }
    int cnt = 0, ans = 0;
    for (int i = 1e6; i > 0; --i) {
        for (int j = 0; j < x[i].size(); ++j) {
            if (cnt == n-1) break;
            if (!j) continue;
            if (dsu.find(x[i][j]) != dsu.find(x[i][j-1])) {
                dsu.bs[dsu.find(x[i][j])] = dsu.find(x[i][j-1]);
                ans += i;
                cnt++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
