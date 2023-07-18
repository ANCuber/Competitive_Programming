#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p, h; cin>>n>>p>>h;    
    int idr;
    vector<int> chg(n+5);
    for (int i = n-1; i >= 0; --i) {
        if (h > (1ll<<i)) {
            chg[i+1] = 1;
            h = (1ll<<(i+1))-h+1;
        } else {
            chg[i+1] = 0;
        }
    }
    if (p <= (1ll<<(n-1))) idr = 0;
    else idr = 1;
    for (int i = 1; i <= n; ++i) {
        if (chg[i]) {
            if (!idr) {
                cout<<'L';
                p = (1ll<<(n-i))-p+1;
            } else {
                cout<<'R';
                p = (1ll<<(n-i+1))-p+1;
            }
        } else {
            if (!idr) {
                cout<<'R';
            } else {
                cout<<'L';
                p -= (1ll<<(n-i));
            }
        }
        
        if (p <= (1ll<<(n-i-1))) idr = 0;
        else idr = 1;
    }
    cout<<endl;
    return 0;
}
