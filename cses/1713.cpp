#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

const int MAXN = 1e6;

bitset<1000005> isp;
vector<int> prm;

void Sieve() {
    isp.set();
    isp[1] = isp[0] = 0;
    for (int i = 2; i <= MAXN; ++i) {
        if (!isp[i]) continue;
        prm.pb(i);
        for (int j = i+i; j <= MAXN; j += i) {
            isp[j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    Sieve();
    while(n--) {
        int x; cin>>x;
        int ans = 1, cnt = 0;
        for (int i = 0; (i < prm.size()) && (x > 1); ++i) {
            if (isp[x]) {
                ans *= 2;
                break;
            }
            cnt = 0;
            while(x%prm[i] == 0) {
                x /= prm[i];
                cnt++;
            }
            ans *= cnt+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
