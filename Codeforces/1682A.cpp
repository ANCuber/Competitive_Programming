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
        string s;cin>>s;
        int len = s.size()/2;
        char mid = s[len];
        int cnt=0;
        for(int i=len;i>=0;i--){
            if(s[i]==mid)  cnt++;
            else break; 
        }
        cout<<cnt*2 - (s.size()%2==0)<<"\n";
    }
}
