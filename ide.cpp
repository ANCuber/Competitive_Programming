#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    while(n--) {
        int a; cin>>a;
        if (a <= 99999 || a >= 1000000) {
            cout<<"No\n";
        } else if ((a/1000)-(a%1000) > 0) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
    
    return 0;
}
