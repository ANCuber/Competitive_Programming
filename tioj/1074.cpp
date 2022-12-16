#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

bool run() {
    vector<int> a(n+1,0);
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        if (a[i] != 1) flag = 1;
        a[i] += a[i-1];
    }
    if (!flag) return 0;
    bitset<500> bs;
    bs.reset();
    for (int i = 0; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            bs[a[j]-a[i]] = 1;
        }
    }
    for (int i = 1; i <= a[n]; ++i) {
        if (!bs[i]) return 0;
    }
    return 1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n && n) {
        if (run()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
