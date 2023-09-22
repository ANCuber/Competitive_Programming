#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct stuff{
    int a[8] ={0};
};
map<int,int> cnt; 
ll P[8][9];
int arr[8];
vector<stuff> num;
int rp[8] = {2,3,}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,k;cin>>n>>k;     
    for(int i=1;i<8;i++){
        for(int j=0;j<8;j++) P[j][i] = P[j][i-1]*P[j][0];
    }
    num.push_back(p);
    for(int t=0;t<n;t++) { 
            char c;cin>>c;
            if(c=='C' || c=='D'){
            stuff tar; int v = (c=='C')?(1):(-1);
            int r;
            if(c=='C'){
            cin>>r;
            for(int i=0;i<8;i++) p.a[i]=0;
            for(int i=0;i<r;i++){
                cin>>p.a[i];        
            }
            num.push_back(p);
            }else{
               int nm;cin>>nm; 
               p = num[nm];
            }
            for(tar.a[0]=0;tar.a[0]<=p.a[0];tar.a[0]++){
                for(tar.a[1]=0;tar.a[1]<=p.a[1];tar.a[1]++){
                    for(tar.a[2]=2;tar.a[2]<=p.a[2];tar.a[2]++){
                        for(tar.a[3]=3;tar.a[3]<=p.a[3];tar.a[3]++){
                            for(tar.a[4]=4;tar.a[4]<=p.a[4];tar.a[4]++){
                                for(tar.a[5]=5;tar.a[5]<=p.a[5];tar.a[5]++){
                                    for(tar.a[6]=6;tar.a[6]<=p.a[6];tar.a[6]++){
                                        for(tar.a[7]=7;tar.a[7]<=p.a[7];tar.a[7]++){
                                            int re = 1;
                                            for(int j=0;j<8;j++) re = re*P[j][tar.a[j]];
                                            cnt[re]+=v;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }else{
            stuff q; 
            int r;cin>>r;
            int re=  1;
            for(int i=0;i<r;i++){
               int num;cin>>num; 
               re = re*P[i][num];
            }
            cout<<cnt[q]<<"\n";
        }
    }
    return 0;
}
