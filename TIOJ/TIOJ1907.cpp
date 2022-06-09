#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int,int>

void update(ll v, int pos, vector<ll> &bit) {
    while(pos <= bit.size()) {
        bit[pos] = max(bit[pos],v);
        pos += (pos & -pos);
    }
}

ll query(int pos, vector<ll> &bit) {
    ll ret = 0;
    while(pos > 0) {
        ret = max(bit[pos],ret);
        pos -= (pos & -pos);
    }
    return ret;
}

int main() {
    int t; cin>>t;
    while(t--) {
        int m; cin>>m;
        vector < pii > baby(m+1);
        baby[0] = {0,0};
        vector <ll> bit(1005,0);
        for (int i = 1; i <= m; ++i) {
            cin>>baby[i].first>>baby[i].second;
        }
        sort(baby.begin(),baby.end());
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            ll cur = query(baby[i].second,bit);
            ans = max(ans,cur+1);
            update(cur+1,baby[i].second,bit);
        }
        cout<<ans<<endl;
    }
    return 0;
}