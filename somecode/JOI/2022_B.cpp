    #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
     
int n, m;
vector<int> a, b;
     
bool check(int mid) {
    int rem = n*m;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            if (a[i]*m >= mid) {
                rem -= mid/a[i]+(mid%a[i] > 0);
            } else {
                int cur = mid-a[i]*m;
                rem -= m;
                rem -= cur/b[i]+(cur%b[i] > 0);
            }
        } else {
            rem -= mid/b[i]+(mid%b[i] > 0);
        }
    }
    return rem >= 0;
}
     
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    a.resize(n), b.resize(n);
    for (auto& i : a) cin>>i;
    for (auto& i : b) cin>>i;
        
    int l = 0, r = 2e18;
    while(r-l > 1) {
        int mid = r+(l-r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout<<l<<endl;
    return 0;
}
