#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=-1;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a!=i){
                if(ans<0) ans=i;
                else ans&=i;
            }
        }
        cout<<ans<<"\n";
    }
}
