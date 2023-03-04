#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
int a[5005];
int n, x;
 
signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d%d",&n,&x);
    map<int,int> mp;
    for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    for (int i = 1; i <= n; ++i) mp[a[i]] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (a[i]+a[j] >= x) continue;
            if (mp.count(x-a[i]-a[j])) {
                if (mp[x-a[i]-a[j]] != i && mp[x-a[i]-a[j]] != j) {
                    printf("%d %d %d\n",i,j,mp[x-a[i]-a[j]]);
                    return 0;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
