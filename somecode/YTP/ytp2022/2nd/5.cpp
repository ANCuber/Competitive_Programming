#pragma GCC optimize("Ofast,unroll-loops")
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
    int difx=0;
    int dify=0;
    string s;cin>>s;
    int dx[6]={1,2,1,-1,-2,-1};
    int dy[6]={1,0,-1,-1,0,1};
    for(auto i :s){
        difx+=dx[i-'A'];
        dify+=dy[i-'A'];
    }
    int ans = abs(dify);
    ans+= (abs(difx)>abs(dify))?((abs(abs(difx)-ans))/2):0;
    cout<<ans<<"\n";
}
