#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int MAX = 200000;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, X;
    cin >> N >> X;
    vector<int> v(MAX + 1);
    cerr << v.size() << endl;

    int l, r;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        v[l]++;
        v[l + r + 1]--;
    }
    for (int i = 1; i <= MAX; i++) {
        v[i] += v[i - 1];
        // cerr << v[i] << ' ' << i << '\n';
    }

    vector<int> cnt(481);
    for (int d = 0; d <= 480; d++) {
        for (int i = 0; d + i * X <= MAX; i++) {
            cnt[d] += v[d + i * X];
        }
    }

    int minId = 0;
    for (int i = 0; i <= 480; i++) {
        if (cnt[i] < cnt[minId]) {
            minId = i;
        }
    }
    
    cout << minId << ' ' << cnt[minId];

    return 0;
}
