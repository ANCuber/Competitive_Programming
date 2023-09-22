#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
bool side[44][44];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,k;cin>>n>>m>>k;       
    int g[n] ;
    for(int i=0;i<n;i++) {cin>>g[i];g[i]--;}
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b; 
        a--;b--;
        if(g[a]==g[b]) continue;
        side[g[a]][g[b]]=1;
        side[g[b]][g[a]]=1;
    }
    int c[k];
    for(int i=0;i<k;i++) cin>>c[i];
    int ans = 0;
    for(int mask=0;mask<(1<<k);mask++){
        int sum = 0;  
        vector<int> in;
        for(int i=0;i<k;i++){
           if((mask>>i)&1){
           in.push_back(i) ;
           sum+=c[i];
           }
        }
        bool works= 1;
        for(auto i : in){
            if(works==0) break;
            for(auto j : in){
                if(side[i][j]==1){works=0;break;}
           }
        }
        if(works){
           ans = max(ans,sum) ;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
