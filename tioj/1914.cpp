#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 205;

int t, n, m;
int c[maxn] = {0};
int dp[maxn][maxn] = {0};

signed main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; ++i) scanf("%d",&c[i]);
        for (int l = 1; l <= n; ++l) {
            for (int i = 1; i+l-1 <= n; ++i) {
                if (l == 1) dp[i][i] = 1;
                else {
                    for (int k = i; k < i+l-1; ++k) {
                        
                    }
                }
            }
        }
    }
    return 0;
}
