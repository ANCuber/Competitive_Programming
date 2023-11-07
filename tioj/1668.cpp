#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

bitset<46345> isp;
vector<int> pri;
const int MX = 46343;

void Sieve() {
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= MX; ++i) {
        if (!isp[i]) continue;
        pri.pb(i);
        for (int j = i+i; j <= MX; j += i) {
            isp[j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    isp.set();
    Sieve();
    while(t--) {
        int l, r; cin>>l>>r;
        int cnt = 0;
        if (2 >= l && 2 <= r) cnt++;
        if (l&1^1) l++;
        for (int i = l; i <= r; i += 2) {
            if (i <= MX) {
                if (isp[i]) cnt++;
                continue;
            }
            int cur = 1;
            for (auto p : pri) {
                if (i%p == 0) {
                    cur = 0;
                    break;
                }
            }
            cnt += cur;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
