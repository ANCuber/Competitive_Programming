#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;     
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    ll tar = 0;
    for(int i=0;i<n;i++) tar+=arr[i];
    vector<int> og(n,0);
    for(int i=0;i<n;i++) og[i]=arr[i];
    tar/=n;
    ll ans = 0;
    ll sum = 0;
    ll rans = 0;
    int i = 0;
    for(int ind=0;ind<2*n;ind++){
        ans+=sum;
        if(arr[i]-tar>0){sum+=arr[i]-tar;arr[i]=tar;}
        else if(sum>tar-arr[i]){
            sum-=(tar-arr[i]);
            arr[i]  = tar;
        }else{
            arr[i]+=sum;
            sum=0;
        }
        //cout<<sum<<" "<<i<<"\n";
        i++;
        if(i==n) i=0;
    }
    for(int g=0;g<n;g++) arr[g]=og[g];
    sum = 0;
    i = 0;
    for(int ind=0;ind<2*n;ind++){
        rans+=sum;
        if(arr[i]-tar>0){sum+=arr[i]-tar;arr[i]=tar;}
        else if(sum>tar-arr[i]){
            sum-=tar-arr[i];
            arr[i]  = tar;
        }else{
            arr[i]+=sum;
            sum=0;
        }
        i--;
        if(i<0) i=n-1;
    }
    cout<<min(ans,rans)<<"\n";
    return 0;
}
