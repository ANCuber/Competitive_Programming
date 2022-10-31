#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

ll n, a, pre = 0, ans = 0;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%lld",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&a);
        if (i) ans += max(0LL,pre-a);
        pre = max(a,pre);
    }
    printf("%lld\n",ans);
    return 0;
}
