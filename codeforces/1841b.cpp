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
    if (n == 1) {
        cin>>n;
        cout<<1<<endl;
        return;
    }
    int fr , bc;
    cin>>fr>>bc;
    cout<<11;
    bool flg = (fr > bc);
    for (int i = 2; i < n; ++i) {
        int x; cin>>x;
        if (!flg) {
            if (x >= bc) {
                bc = x;
                cout<<1;
            } else if (x <= fr){
                flg = 1;
                bc = x;
                cout<<1;
            } else {
                cout<<0;
            }
        } else {
            if (x <= fr && x >= bc) {
                cout<<1;
                bc = x;
            } else {
                cout<<0;
            }
        }
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
