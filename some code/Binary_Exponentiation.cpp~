#include <bits/stdc++.h>
using namespace std;

int BE_pow(int a, int n, int mod) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans%mod;
}

int main() {
    int a, n, mod;
    cin>>a>>n>>mod;
    cout<<BE_pow(a,n,mod)<<endl;
    return 0;
}