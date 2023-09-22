#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a = 1;int b=  1;     
    int n;cin>>n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y; 
        if(x!=3){
            cnt+=(a!=x) ;
            a=x;
        }
        if(y!=3){
           cnt+=(b!=y) ;
           b=y;
        }
    }
    cout<<cnt<<"\n";
    
    return 0;
}
