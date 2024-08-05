#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, Q;
    string s;
    cin >> N >> s >> Q;

    vector<int> cnt(N);
    for (int i = 1; i < N; i++) {
        if (s[i] == '9' && s[i - 1] == '4') cnt[i]++;
        cnt[i] += cnt[i - 1];
    }

    while (Q--) {
        ll l, r;
        cin >> l >> r;
        --l, --r;
        
        ll ans = r - l;
        int count = cnt[r] - cnt[l];
        ans -= count;

        if (ans == 0) {
            cout << -1 << '\n';
            continue;
        }

        cout << 2 << ' ' << ans << '\n';
    }

    return 0;
}
