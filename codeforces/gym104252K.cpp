#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

pair<int, int> to_xy(int n) {
    return {n % 80, n / 80 * 2 + 1};
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;

    k--;
    vector< vector<int> > v(14);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 14; j++) {
            if (i & (1 << j)) v[j].push_back(i);
        }
    }
    int cnt = 0;

    for (auto& V: v) if (V.size()) cnt++;
    
    cout << cnt << '\n';

    for (auto& V: v) {
        if (V.empty()) continue;
        
        cout << V.size() + 4100; 
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 81; j++) {
                cout << ' ' << j << ' ' << i * 2;
            }
            cout << " 81 " << i * 2 - 1;
        }

        for (auto& n: V) {
            auto [x, y] = to_xy(n);
            cout << ' ' << x << ' ' << y;
        }
        cout << '\n';
    }
    
    return 0;
}
