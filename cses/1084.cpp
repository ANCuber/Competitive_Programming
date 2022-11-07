#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main() {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    for (int i = 0; i < m; ++i) scanf("%d",&b[i]);
    sort(a.begin(),a.end()), sort(b.begin(),b.end());
    int ap = 0, bp = 0, cnt = 0;
    while(ap < n && bp < m) {
        if (a[ap]-b[bp] < -k) {
            ap++;
        } else if (a[ap]-b[bp] > k) {
            bp++;
        } else {
            ap++,bp++,cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
