#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    if (n & 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << (n * n / 4) << '\n';

    for (int i = 1; i <= n; i += 2) {
        for (int j = i + 1; j <= n; j++) {
            cout << i << ' ' << j << '\n';
        }
    }
}
