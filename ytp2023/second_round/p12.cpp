#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
const int N = 1e6+5;
bool issq[N];
const int MOD = 21610411;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;     

    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i*i){
            issq[j]=1;
        }
    }
    int rsum = 0;
    for(int i=1;i<=n;i++)  {
        if(issq[i]) continue;
        int sum = 0;
        for(int j=1;j*j*i<=n;j++){
            sum = (sum+j)%MOD; 
        }
        //cout<<sum<<" "<<i<<"\n";
        rsum+=((sum*sum)%MOD*i)%MOD;
        rsum%=MOD;
    }
    cout<<rsum<<"\n";
    return 0;
}
