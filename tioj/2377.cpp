#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> a(n+2);
    int sum = 0, flg = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum += a[i];
    }
    for (int i = n; i > 0; --i) {
        int cur = 0;
        for (int j = i; j <= n; j += i) cur += a[j];
        if (sum == cur) {
            flg = i;
            break;
        }
    }
    //cout<<"pass"<<endl; return 0;
    if (!flg) {
        cout<<"1\n";
        cout<<sum<<'\n';
    } else {
        cout<<n-n/flg+1<<'\n';
        cout<<sum;
        for (int i = 0; i < n-n/flg; ++i) cout<<" 0";
        cout<<'\n';
    }
    return 0;
}
