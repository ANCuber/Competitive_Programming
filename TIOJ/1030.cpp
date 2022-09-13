#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector <int> v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
            v[i]--;
        }
        int ans = 0;
        sort(v.begin(),v.end(),greater<int>());
        ans += (v[0]<<1);
        ans++;
        for (int i = 1; i < n; ++i) {
            ans += (v[i]+1);
        }
        cout<<ans+2<<endl;
    }
    return 0;
}
