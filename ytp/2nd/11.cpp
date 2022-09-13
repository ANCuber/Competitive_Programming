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
    
    int testdata;
    cin >> testdata;

    while (testdata--) {
        int length;
        cin >> length;
        vector<ll> v(length);
        for (auto& n: v) cin >> n;
        sort(v.begin(), v.end());

        ll l = 1, r = v.back(), m;
        while (r - l > 1) {
            m = l + r >> 1;
            (m * (m + 1) / 2 <= v.back() ? l : r) = m;
        }

        auto it = lower_bound(v.begin(), v.end(), l);
        ll sum = v.end() - it;
        while (it != v.end()) {
            sum += *it - l;
        }

        cout << (sum & 1 ? "MM\n" : "TT\n");
    }
}
