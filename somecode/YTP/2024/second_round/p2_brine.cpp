#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;

    int x, y, z;
    cin >> x >> y >> z;

    vector<int> f;
    for (int i = 1; i*i <= K; i++) {
        if (K % i == 0) f.push_back(i); 
    }

    vector<int> v(N);
    for (auto& n: v) cin >> n;
    
    int ans = 1e18;

    for (int msk = 0, M = 1 << (N * 2); msk < M; msk++) {
        int A = 0, B = 0, C = -2 * z;
        for (int i = 0, m = msk; m; i++, m >>= 2) {
            if ((m & 3) == 3 || (m & 3) == 0) continue;
            if ((m & 1)) A += v[i];
            if ((m & 2)) B += v[i];
            C += z;
        }

        if (A == 0 || B == 0) continue;

        if (A > B) swap(A, B);


        for (int i = 0; i < f.size(); i++) {
            int f1 = f[i], f2 = K / f[i];
            int cost = C;
            cost += (A > f1 ? y : x) * abs(A - f1);
            cost += (B > f2 ? y : x) * abs(B - f2);
            ans = min(ans, cost);
        }

    }

    cout << ans << '\n';

    return 0;
}
