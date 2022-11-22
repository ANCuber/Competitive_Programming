#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int long long

const int mod = 1e9+7;

int power(int a, int n) {
    int ans = 1, base = a;
    while(n) {
        if (n&1) ans = ans*base%mod;
        base = base*base%mod;
        n >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k; 
    if (k >= 3) return 0;
    vector<int> a(n);
    vector<int> ans(n+5), cnt(n+5,0);
    for (auto& i : a) cin>>i;
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            if (i) cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i&j) >= n) continue;
            cnt[i&j]++;
            ans[i&j] += a[i]*a[j]%mod;
            ans[i&j] %= mod;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout<<' ';
        //cout<<ans[i];
        cout<<(ans[i]*power(cnt[i],mod-2)%mod);
    }
    cout<<endl;
    return 0;
}
