#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k, m, cur = 0;

signed main() {
    while(true) {
        scanf("%d%d%d",&n,&k,&m);
        if (!n && !k && !m) return 0;
        k--;
        cur = 0;
        for (int i = n-m+1; i <= n; ++i) {
            cur = (cur+k)%i;
        }
        printf("%d\n",cur+1);
    }
}
