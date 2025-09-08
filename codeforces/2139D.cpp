#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SEG {
    vector<int> a;
    void init(int _n) {
        a.assign(4 * _n + 5, 0);
    }
    void mdf(int l, int r, int p, int t, int x) {
        if (l == r) {
            a[p] = x;
            return;
        }
        int mid = (l + r) / 2;
        if (t <= mid) mdf(l, mid, p << 1, t, x);
        else mdf(mid + 1, r, p << 1 | 1, t, x);
        a[p] = min(a[p << 1], a[p << 1 | 1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return a[p];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(l, mid, p << 1, ql, qr);
        else if (ql > mid) return query(mid + 1, r, p << 1 | 1, ql, qr);
        else return min(query(l, mid, p << 1, ql, qr), query(mid + 1, r, p << 1 | 1, ql, qr));
    }
} seg;

void solve() {
    int n, q; cin >> n >> q;
    seg.init(n);
    vector<int> a(n + 3), stk, LL(n + 3, -1), RR(n + 3, -1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> p(n + 3, 1e9);
    stk.push_back(1);
    for (int i = 2; i < n; ++i) {
        if (a[stk[0]] < a[i]) {
            stk.clear();
            stk.push_back(i);
            continue;
        }
        int l = 0, r = (int)stk.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[stk[mid]] > a[i]) l = mid;
            else r = mid;
        }
        while (!stk.empty() && a[stk.back()] < a[i]) 
            stk.pop_back();
        stk.push_back(i);
        LL[i] = stk[l];
    }
    stk.clear();
    stk.push_back(n);
    for (int i = n - 1; i > 1; --i) {
        if (a[stk[0]] > a[i]) {
            stk.clear();
            stk.push_back(i);
            continue;
        }
        int l = 0, r = (int)stk.size();

        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[stk[mid]] < a[i]) l = mid;
            else r = mid;
        }
        while (!stk.empty() && a[stk.back()] > a[i]) 
            stk.pop_back();
        stk.push_back(i);
        RR[i] = stk[l];
    }
    for (int i = 2; i <= n; ++i) {
        if (LL[i] < 0 || RR[i] < 0) continue;
        p[LL[i]] = min(p[LL[i]], RR[i]);
    }
    for (int i = 1; i <= n; ++i)
        seg.mdf(1, n, 1, i, p[i]);
    while (q--) {
        int l, r; cin >> l >> r;
        if (r - l + 1 <= 2 || seg.query(1, n, 1, l, r) > r) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
