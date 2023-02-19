#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

int num[22] = {0,1,5,10,50,100,500,1000,5000,10000,50000,1000000,5000000,10000000,50000000,100000000,500000000,
1000000000,5000000000,10000000000,50000000000};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int sum = 0, un = 0;
    for (int i = 1; i <= n; ++i) {
        int c; cin>>c;
        if (sum < num[i] && i != 1) {
            un += (num[i]-sum-1)*c%mod;
            un %= mod;
        }
        sum += num[i]*c%mod;
        sum %= mod;
    }
    sum -= un;
    if (sum < 0) cout<<sum+mod<<endl;
    else cout<<sum%mod<<endl;
    
    return 0;
}
