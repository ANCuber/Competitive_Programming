#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Rng{
    int l = 0, r = 0;
    bool operator<(Rng b) {
        return r < b.r;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<Rng> a(n+1);
    for (int i = 1; i <= 2*n; ++i) {
        int x; cin>>x;
        if (!a[x].l) a[x].l = i;
        else a[x].r = i;
    }
    sort(a.begin(),a.end());
    vector<int> dp(n+1,1), bdr(n+1,1e9);
    bdr[0] = dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (bdr[j] >= a[i].l) continue;
            
            if (dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                if (a[j].r < a[i].l) bdr[i] = bdr[j];
                else bdr[i] = a[j].r;
            } else if (dp[j]+1 == dp[i]) {
                if (a[j].r < a[i].l) {
                    bdr[i] = min(bdr[i],bdr[j]);
                } else {
                    bdr[i] = min(bdr[i],a[j].r);
                }
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}

