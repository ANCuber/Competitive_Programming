#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int sum = 0, mx = 0;
    while(n--) {
        int x; cin>>x;
        sum += x;
        mx = max(mx,x);
    }
    sum -= mx;
    if (sum <= mx) {
        cout<<mx*2<<endl;
    } else {
        cout<<sum+mx<<endl;
    }
    return 0;
}
