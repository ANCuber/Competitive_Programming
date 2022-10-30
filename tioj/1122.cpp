#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

int n;
int a[21][21] = {0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>a[1][1]) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i==1 && j==1) continue;
                if (j==1) a[i][1] = a[1][1]+i;
                else if((i+j)&1) a[i][j] = ((a[i][j-1]*17)%103)*(-1);
                else a[i][j] = ((a[i][j-1]*17)%103);
            }
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] += a[i-1][j];
            }
        }
        int ans = -2e18-5, sum;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                sum = 0;
                for (int k = 1; k <= n; ++k) {
                    sum = max(sum,0LL)+a[j][k]-a[i-1][k];
                    ans = max(ans,sum);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
