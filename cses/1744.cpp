#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int a, b;

int slv(int x, int y) {
    if (x == y) return 0;
    return 1+slv(min(y-x,x),max(y-x,x));
}

signed main() {
    scanf("%d%d",&a,&b);
    printf("%d",slv(min(a,b),max(a,b)));
    return 0;
}
