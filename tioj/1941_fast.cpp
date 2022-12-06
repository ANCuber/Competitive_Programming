#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int n, l, r;
multiset <int> s;

signed main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d",&l,&r);
        s.insert(l);
        auto iter = s.upper_bound(r);
        if (iter != s.end()) s.erase(iter);
    }
    printf("%d\n",s.size());
    return 0;
}
