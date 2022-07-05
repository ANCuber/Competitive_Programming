#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

vector<int> a;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        a.assign(n+1,0);
        map <int,int> mp;
        mp[0] = 0;
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            if (a[i] > 0) a[i] = 1;
            else if (a[i] < 0) a[i] = -1;
            a[i] += a[i-1];
            if (mp.find(a[i]) != mp.end()) {
                p = max(p,i-mp[a[i]]);
            } else {
                mp[a[i]] = i;
            }
        }
        cout<<p<<endl;
    }
    return 0;
}
