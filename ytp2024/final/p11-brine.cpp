#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct segTree {
    int N;
    vector<int> node;

    segTree(int n): N(n), node (n << 1) {}
    
    void modify(int i, int x) {
        for (i += N; i > 0; i >>= 1) node[i] = max(node[i], x); 
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, node[l++]);
            if (r & 1) ans = max(ans, node[--r]);
        }
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int type;
        cin >> type;
        int i, x, y, a, b, k;
        if (type == 1) {
            cin >> x >> y;

        } else if (type == 2){
            cin >> a >> b;
        } else {
            cin >> id >> k; 
            cout << tree.query(0, mp[k]);
        }
    }


    return 0;
}
