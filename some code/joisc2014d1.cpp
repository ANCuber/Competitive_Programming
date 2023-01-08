#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int k;

struct Query{
    int l, r, id;
    bool operator<(Query b) {
        if (l/k == b.l/k) return r < r.b;
        return l/k < b.l/k;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<int> x(n+1);
    for (int i = 1; i <= n; ++i) cin>>x[i];
    for (int i = 1; i <= Q; ++i) {
        
    }
    
    return 0;
}
