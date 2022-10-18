#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin>>h[i];
    vector<int> dp(n,0);
    dp[0] = 1;
    int ctrl = 1;//high
    for (int i = 1; i < n; ++i) {
        if (ctrl) {
            if (h[i] < h[i-1]) ctrl = 0;
            dp[i] = dp[i-1];
        } else {
            if (h[i] > h[i-1]) {
                ctrl = 1;
                dp[i] = dp[i-1]+2;
            } else {
                dp[i] = dp[i-1];
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
