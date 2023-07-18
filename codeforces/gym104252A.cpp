#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,h,w;cin>>n>>h>>w;
    for(int i=0;i<n;i++){
        char g;cin>>g;
        if(g=='Y'){
            h--;w++;
            cout<<"Y ";
        }else{
            if(w==0){
                h--;w++;
                cout<<"Y ";
            }else{
                cout<<"N "; 
            }
        }
        cin>>g;
        if(g=='Y'){
            h++;w--;
            cout<<"Y\n";
        }else{
            if(h==0){
               h++;w--;
               cout<<"Y\n";
            }else{
                cout<<"N\n"; 
            }
        }
    }
    
    return 0;
}
