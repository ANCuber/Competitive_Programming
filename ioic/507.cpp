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
    int n; cin>>n;    
    if (n > 30) {
        cout<<"No"<<endl;
    } else {
        cout<<"Yes"<<endl;
        for (int i = 0; i < n; ++i) {
            if (i) cout<<' ';
            cout<<(1<<i);
        }
        cout<<endl;
    }
    
    return 0;
}
