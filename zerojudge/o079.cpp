#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    int n, k; cin>>n>>k;
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] += a[i-1];
    }
    map<int,vector<pair<int,int> > > mp;//odd - even
    int cnt = 0;//counting odd numbers
    for (int i = n; i > 0; --i) {
        cnt += (a[i]-a[i-1])&1;
        mp[cnt-(n-i+1-cnt)].push_back({a[n]-a[i-1],i});
    }
    cnt = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        i?(cnt += (a[i]-a[i-1])&1):(cnt = 0);
        int cur = (i-cnt)-cnt;//even - odd
        if (!cur && a[i] <= k) ans = max(ans,a[i]);
        if (!mp.count(cur)) continue;
        int l = 0, r = mp[cur].size(), mid;
        while(r-l > 1) {
            mid = (r+l)>>1;
            if (mp[cur][mid].second > i && mp[cur][mid].first+a[i] <= k) l = mid;
            else r = mid;
        }
        //cout<<i<<' '<<mp[cur][l].second<<' '<<mp[cur][l].first+a[i]<<endl;
        if (mp[cur][l].second > i && a[i]+mp[cur][l].first <= k) ans = max(ans,a[i]+mp[cur][l].first);
    }
    cout<<ans<<'\n';
    return 0;
}

