#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
int a[300005];
bool comp(int x,int y){
    return a[x]>a[y] ;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n;cin>>n;     
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> order(n);
    for(int i=0;i<n;i++) order[i]=i+1;
    sort(order.begin(),order.end(),comp);
    int ans[n+1];
    int dis[n+1];
    int cur = 1;
    int head = 0;
    dis[order[0]]=0;
    ans[order[0]]=0;
    while(cur<n){
        for(int t=0;t<a[order[head]];t++){
            ans[order[cur]] = order[head];
            dis[order[cur]]=dis[order[head]]+1;
            cur++;
        }
        head++;
    }
    int maxn = 0;
    for(int i=1;i<=n;i++){
        maxn = max(maxn,dis[i]) ;
    }
    cout<<maxn<<"\n";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    }
    return 0;
}
