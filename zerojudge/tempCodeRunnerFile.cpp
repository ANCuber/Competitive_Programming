#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a, b;
    cin>>a>>b;
    long long ans = 1;
    while(b>0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
        if (ans > 10007) ans %= 10007;
    }
    cout<<ans<<'\n';
    return 0;
}