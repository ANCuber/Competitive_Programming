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
    int n; cin>>n;    
    while(n--) {
        int cnt = 0;
        int x; cin>>x;
        for (int i = 1; i*i <= x; ++i) {
            if (x%i == 0) cnt += 2;
            if (i*i == x) cnt--;
        }
        cout<<cnt<<endl;
    }
    
    return 0;
}
