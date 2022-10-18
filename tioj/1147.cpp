#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector< pii > ct(n);
    for (int i = 0; i < n; ++i) {
        cin>>ct[i].first>>ct[i].second;
    }
    sort(ct.begin(),ct.end());
    ll minn = 1e12;
    pii ans = {-1,-1};
    for (int i = 0; i < n; ++i) {
        ll cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += abs(ct[i].first - ct[j].first);
            cur += abs(ct[i].second - ct[j].second);
        }
        if (cur < minn) {
            minn = cur;
            ans = ct[i];
        }
    }
    cout<<ans.first<<' '<<ans.second<<endl;
    cout<<minn<<endl;
    return 0;
}
