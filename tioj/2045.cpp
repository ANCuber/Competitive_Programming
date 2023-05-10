#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dg[100005] = {0};
int n, m, u, v, flg = 1;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%d%d",&n,&m);
    while(m--) {
        scanf("%d%d",&u,&v);
        dg[u]++, dg[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (dg[i] != n-1) {
            flg = 0;
            break;
        }
    }
    if (!flg) printf("%d\n",n);
    else printf("0\n");
    return 0;
}
