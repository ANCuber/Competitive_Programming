#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, k;

int slv(int cnt, int r) {
    if (cnt == k) return 0;
    return (slv(cnt+1,r-1)+m)%r;
}

signed main() {
    scanf("%d%d%d",&n,&m,&k);
    printf("%d\n",slv(0,n)+1);
    return 0;
}
