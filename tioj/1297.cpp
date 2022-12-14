#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    while(cin>>n) {
        if (n < 0) {
            cout<<"stupid\n";
            continue;
        }
        for (int i = n-100; i <= n; ++i) {
            if (i+(i/100) >= n) {
                if (i > 1024 || (i+(i/100)) > n) {
                    cout<<"stupid\n";
                    break;
                }
                cout<<i<<endl;
                break;
            }
        }
    }
    
    return 0;
}
