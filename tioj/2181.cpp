#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

struct club{
    int x, c;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, n; cin>>a>>n;
    vector<club> cb(n+1);
    vector<int> dp(a+1,-1e9);
    for (int i = 1; i <= n; ++i) cin>>cb[i].x>>cb[i].c;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = a; j >= 0; --j) {
            if (j >= cb[i].c) dp[j] = max(dp[j],dp[j-cb[i].c]+cb[i].x);
            else dp[j] = dp[j];
        }
    }
    int m = -1e9, s = -1;
    for (int i = 0; i <= a; ++i) {
        if (dp[i] > m) {
            m = dp[i];
            s = i;
        }
    }
    cout<<m<<' '<<s<<endl;

    return 0;
}
