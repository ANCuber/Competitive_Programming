#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        if (n == 1) {
            int x, y; cin>>x>>y;
            if (x*y) {
                cout<<-1<<endl;
            } else {
                cout<<0<<endl;
            }
            continue;
        }
        vector<pii> a(n);
        int blk = 0, wht = 0, sum = 0;
        for (auto& [i,j] : a) {
            cin>>i>>j;
            if (i < j) {
                blk = 1;
                sum += i;
            } else {
                wht = 1;
                sum += j;
            }
        }
        if (blk&wht || !sum) {
            cout<<sum<<endl;
        } else {
            int mn = 1e12;
            if (blk) {
                for (int i = 0; i < n; ++i) mn = min(a[i].second-a[i].first,mn);
            } else {
                for (int i = 0; i < n; ++i) mn = min(a[i].first-a[i].second,mn);
            }
            cout<<sum+mn<<endl;
        }
    }
    return 0;
}
