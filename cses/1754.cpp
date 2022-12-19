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
    int t; cin>>t;    
    while(t--) {
        int a, b; cin>>a>>b;
        if (a > b) swap(a,b);
        if (a < b) {
            if (b == 2*a) {
                cout<<"YES\n";
            } else if (b > 2*a) {
                cout<<"NO\n";
            } else {
                if ((a-b+a)%3) cout<<"NO\n";
                else cout<<"YES\n";
            }
        } else {
            if (a%3) cout<<"NO\n";
            else cout<<"YES\n";
        }

    }
    
    return 0;
}
