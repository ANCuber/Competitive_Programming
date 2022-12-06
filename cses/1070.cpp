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
    if (n == 1) {
        cout<<"1\n";
    } else if (n <= 3) {
        cout<<"NO SOLUTION\n";
    } else if (n == 4) {
        cout<<"3 1 4 2\n";
    } else {
        for (int i = 1; i <= n; i += 2) {
            if (i != 1) cout<<' ';
            cout<<i;
        }
        for (int i = 2; i <= n; i += 2) {
            cout<<' '<<i;
        }
        cout<<endl;
    }
    
    return 0;
}
