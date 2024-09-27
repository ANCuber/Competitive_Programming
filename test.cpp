#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

signed main() {
    int A, B;
    scanf("%lld%lld", &A, &B);
    if (A < B) swap(A, B);
    int a = A, b = B;
    int HCF, LCM, num = -1;
    while(num != 0) {
        num = a%b;
        a = b;
        b = num;

        if (num == 0) {
            HCF = a;
            LCM = A*B/HCF;
        }
    }
    printf("%d\n", HCF);
    return 0;
}
