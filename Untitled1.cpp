#include <bits/stdc++.h>
#define int long long

using namespace std;

int const maxn=1e6+500;
int const mod=1e9+7;
int dp[3][maxn];
int n,m;

signed main(){
    cin>>m>>n;

    for(int i=0;i<=n;i++) dp[0][i]=1;
    dp[1][0]=1;

    int sum=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i%2][j]=dp[i%2][j-1]+dp[(i+1)%2][j];
            sum=(sum+ dp[i%2][j-1]*i) %mod;
            if(j<n && i<m) sum=(sum+ i*j*dp[i%2][j-1])%mod;
        }
    }
    cout<<sum<<endl;
}