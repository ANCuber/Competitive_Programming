#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l = 0, r = 1e12+1;
    int cur, pos = 0;
    while(r-l > 1) {
        int mid = (l+r)>>1;
        pos+=mid;
        cout<<"? "<<pos<<endl;
        int x;
        cin>>x;
        if (cur != pos-x) {
            r = mid;
        } else {
            l = mid;
        }
        cur = pos-x;
    }
    cout<<"! "<<r<<endl;
    return 0;
}
