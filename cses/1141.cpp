#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

multiset<int> s;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n+1);
    int lp = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        s.insert(a[i]);
        while(s.count(a[i]) > 1) {
            s.erase(s.find(a[++lp]));
        }
        ans = max(ans,int(s.size()));
    }
    cout<<ans<<endl;
    return 0;
}
