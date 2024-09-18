#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> isp(1000005,1), a(1000005,1);

void Seive() {
    for (int i = 2; i <= 1e6; ++i) {
        if (isp[i]) {
            a[i] = 2;
            for (int j = i+i; j <= 1e6; j += i) {
                isp[j] = 0;
                int cur = 0, tmp = j;
                while(tmp%i == 0) {
                    tmp /= i;
                    cur++;
                }
                a[j] *= cur+1;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin>>T;    
    Seive();
    vector<ll> ans(1000005);
    ans[1] = 1, ans[2] = 5;
    for (int i = 3; i <= 1e6; ++i) ans[i] = 3*(a[i])+ans[i-1]-2;
    while(T--) {
        int N; cin>>N;
        cout<<ans[N]<<endl;
    }
    return 0;
}
