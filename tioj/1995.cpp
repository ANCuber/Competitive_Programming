#pragma GCC optimize("O3")
//#define _GLIBCXX_IOSTREAM
//#include <bits/stdc++.h>
#include "lib1995.h"

using namespace std;

const int maxn = 200000;
const int maxq = 200000;

int n, q, ret;
vector<int> QL(maxq+1), QR(maxq+1), a((maxn<<1)-1);

inline void init() {
    for (int i = 0; i < n; ++i) scanf("%d",&a[i+n]);
    for (int i = n-1; i > 0; --i) a[i] = max(a[i<<1],a[i<<1|1]);
}

inline int query(int l, int r) {
    ret = 0;
    for (l+=n, r+=n; r > l; l>>=1, r>>=1) {
        if (l&1) ret = max(ret,a[l++]);
        if (r&1) ret = max(ret,a[--r]);
    }
    return ret;
}

signed main() {
    scanf("%d%d",&n,&q);
    for (int i = 0; i < q; ++i) scanf("%d%d",&QL[i],&QR[i]);
    init();
    for (int i = 0; i < q; ++i) printf("%d\n",query(QL[i]-1,QR[i]));
    return 0;
}
