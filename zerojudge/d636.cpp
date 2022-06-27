#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a, b;
    cin>>a>>b;
    long long ans = 1;
    a %= 10007;
    while(b>0) {
        if (b & 1) {
            ans = ans*a%10007;
        }
        a = a*a%10007;
        b >>= 1;
    }
    cout<<ans<<'\n';
    return 0;
}