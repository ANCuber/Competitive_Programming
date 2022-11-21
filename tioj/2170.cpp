#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, m;

inline int power(int a, int p) {
    int ans = 1, base = a;
    while(p) {
        if (p&1) ans = ans*base%m;
        base = base*base%m;
    }
    return ans;
}

signed main() {
    scanf("%d%d",&n,&m);
    int v[n+5][n+5], tar[n+5];
    for (int i = 1; i <= n; ++i) scanf("%d%d%d",&tar[1],&tar[2],&tar[3]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&v[j][i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            
        }
    }

    return 0;
}
