#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=1e6+500;
int const mod=1e9+7;
int dp[3][maxn];
int n,m;

int c(int m, int n) {
    if (n == 0 || n == m) return 1;
    return (c(m-1,n)%mod+c(m-1,n-1)%mod)%mod;
}

signed main(){
    cin>>m>>n;
    int x = c(m+n,min(m,n))%mod;

    cout<<((x*n*m)/2)%mod<<endl;
}
