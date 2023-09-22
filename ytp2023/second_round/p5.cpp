#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    int U = 1e9 + 7, D = 0, L = 1e9 + 7, R = 0;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        U = min(U, y);
        D = max(D, y);
        L = min(L, x);
        R = max(R, x);
    }

    int dist = max((D - U + 1) / 2, (R - L + 1) / 2);
    cout << dist << '\n';
    cout << max(0,min(L+dist, R - dist)) << ' ' << max(0, min(U+dist,D - dist)) << '\n';
    return 0;
}
