#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int a, b; 
    cin >> a >> b;
    if (a == b) cout << 0;
    else if (a % b == 0 || b % a == 0) cout << 1;
    else cout << 2;
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
