#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    int s = 0, cnt = 0, flg = 0;
    for (int i = 1; i <= n; ++i) {
        int a; cin>>a;
        if (flg) s &= a;
        else s = a;
        
        if (s == 0) {
            cnt++;
            flg = 0;
        } else {
            flg = 1;
        }
        
        //cout<<s<<' ';
    }
    if (s && !cnt) cnt++;
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
