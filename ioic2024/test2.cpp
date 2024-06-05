#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a(1000005,0);
    for (int i = 1; i <= 1e5; ++i) {
        for (int j = 1; j*j <= i; ++j) {
            if (i%j == 0 && i != j*j) a[i] += 2;
            else if (i%j == 0 && i == j*j) a[i]++;
            cout<<a[i]<<',';
        }
    }
    return 0;
}

