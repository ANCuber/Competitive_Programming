#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 2e5;

int n, Q, k, a, cnt = 0;
int arr[maxn+5], ans[maxn+5], num[maxn+5] = {0};
map<int,int> mp;

struct Query{
    int l, r, id;
    bool operator<(Query b) {
        if (l/k == b.l/k) return r < b.r;
        return l/k < b.l/k;
    }
} q[maxn+5];

inline void add(int p) {
    if (num[arr[p]]++ == 0) cnt++;
}

inline void sub(int p) {
    if (--num[arr[p]] == 0) cnt--;
}

signed main() {
    scanf("%d%d",&n,&Q);
    k = n/sqrt(Q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a);
        if (mp.find(a) != mp.end()) arr[i] = mp[a];
        else arr[i] = mp[a] = i;
    }
    for (int i = 1; i <= Q; ++i) {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id = i;
    }
    sort(q+1,q+Q+1);
    int l = 1, r = 0, ql, qr;
    for (int i = 1; i <= Q; ++i) {
        ql = q[i].l, qr = q[i].r;
        while(l < ql) sub(l++);
        while(r > qr) sub(r--);
        while(l > ql) add(--l);
        while(r < qr) add(++r);
        ans[q[i].id] = cnt;
    }
    for (int i = 1; i <= Q; ++i) printf("%d\n",ans[i]);
    return 0;
}
