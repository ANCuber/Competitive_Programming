#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back


struct Range{
    int l, r;
    bool operator<(Range b) {
        if (r == b.r) return l < b.l;
        return r < b.r;
    }
};

signed main() {
    int n, q, ans = 0, i, lp = 1;
    scanf("%d%d",&n,&q);
    vector<Range> a(q);
    vector<int> s(n+2,0);
    for (i = 0; i < q; ++i) scanf("%d%d",&a[i].l,&a[i].r);
    sort(a.begin(),a.end());
    for (i = 0, lp = 1; i < q; ++i) {
        while(lp <= a[i].r) {
            s[lp] += s[lp-1];
            lp++;
        }
        if (s[a[i].r]-s[a[i].l-1] == 0) {
            s[a[i].r]++;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
