#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct hhh{
    int a, b;
    bool operator<(hhh y) {
        return a*y.b > b*y.a;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<hhh> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr.begin(),arr.end());
    int i = 0, ans = 0;
    for (; i < n; ++i) {
        if (arr[i].b > m) break;
        ans += arr[i].a;
        m -= arr[i].b;
    }
    if (i != n) ans += m*arr[i].a/arr[i].b;
    cout<<ans<<endl;
    return 0;
}
