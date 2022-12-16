#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        int k; cin>>k;
        int sq = sqrt(k), ans = 0, cnt = 0;
        for (int i = 1; i <= sq; ++i) {
            if (k%i == 0) {
                if (k/i != i) {
                    cnt += 2;
                    ans += (i+k/i);
                } else {
                    cnt++;
                    ans += i;
                }
            }
        }
        cout<<ans*cnt<<endl;
    }
    return 0;
}
