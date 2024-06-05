#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int M = 998244353;
vector<ll> inv(5005), fac(5005), inf(5005);

void INV_Others() {
    inv[1] = inf[1] = inf[0] = fac[1] = fac[0] = 1;
    for (int i = 2; i <= 5000; ++i) {
        inv[i] = inv[M%i]*(M-(M/i))%M;
        fac[i] = fac[i-1]*i%M;
        inf[i] = inf[i-1]*inv[i]%M;
    }
}

inline ll C(int a, int b) {
    return fac[a]*inf[a-b]%M*inf[b]%M;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin>>N;    
    INV_Others();
    vector<int> a(N+2), cnt(N+2,0);
    vector<vector<ll> > dp(N+2,vector<ll>(N+2,0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        if (a[i] != -1) cnt[a[i]]++;
    }
    int tot = N, cur = 1, sum = 0;
    for (int i = 1; i <= N; ++i) {
        tot -= cnt[i];
        if (cnt[i] > i) {
            cout<<0<<endl;
            return 0;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (!cnt[i]) continue;
        sum += i;
        cur = cur*C(tot,i-cnt[i])%M*fac[i-1]%M;
        tot -= (i-cnt[i]);
    }
    if (sum > N) {
        cout<<0<<endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {//size
        for (int j = 0; j <= N; ++j) {//the number of all the items selected
            if (!cnt[i] && j-i >= 0) dp[i][j] = dp[i-1][j-i]*fac[i-1]%M*C(tot-j+i,i)%M;
            dp[i][j] = (dp[i][j]+dp[i-1][j])%M;
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[N][N-sum]*cur%M<<endl;
    return 0;
}
