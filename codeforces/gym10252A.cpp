#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
pair<int,int> side[1005];
int in[1005];
int cnt = 0;
bitset<1005> vis;
void dfs(int cur,int v){
    if(cur==v) return;
    cnt++;
    vis[cur]=1;
    if(!vis[side[cur].first]  ) {
       dfs(side[cur].first,v) ;
    }
    if(!vis[side[cur].second]){
        dfs(side[cur].second,v) ;
    }
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;     
    for(int i=1;i<=n;i++) {
        cin>>side[i].first>>side[i].second;
        in[side[i].first]++;
        in[side[i].second]++;
    }
    bool work[n+1] ={0};
    for(int i=1;i<=n;i++){
        in[side[i].first]--;
        in[side[i].second]--;
        pair<int,int> minn = {1e9,-1};
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            minn = min(make_pair(in[j],j),minn);
        }
        vis.reset();
        cnt=0;
        dfs(minn.second,i);
        if(cnt==n-1) work[i]=1;
        in[side[i].first]++;
        in[side[i].second]++;
        if(in[i]==0) work[i]=0;
    }
    for(int i=1;i<=n;i++) cout<<"NY"[work[i]];
    cout<<"\n";
    return 0;
}
