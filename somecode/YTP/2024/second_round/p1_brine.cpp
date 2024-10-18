#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    auto s2 = s;


    bool flg = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && flg == 0) {
            s2[i] = '2';
            flg = 1;
            continue;
        }

        if (flg) s2[i] = '0';
    }

    vector<int> v(s.size()), v2(s.size());

    for (int i = 0; i < s.size(); i++) {
        v[i] = s[s.size() - 1 - i] - '0';
        v2[i] = s2[s.size() - 1 - i] - '0';
    }

    for (int i = 0; i < s.size(); i++) {
        v2[i] -= v[i];
        if (v2[i] < 0) {
            v2[i] += 10;
            v2[i + 1]--;
        }
    }
    
    flg = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (i > 0 && flg && v2[i] == 0) continue;
        if (v2[i]) flg = 0;
        cout << v2[i];
    }

    return 0;
}
