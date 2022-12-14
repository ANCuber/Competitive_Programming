#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int a[13] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int n;

signed main() {
    scanf("%d",&n);
    printf("%d\n",a[n]);
}
