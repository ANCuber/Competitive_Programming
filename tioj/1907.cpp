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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int m; cin>>m;
        vector < pii > baby(m+2);
        baby[0] = {0,0};
        baby[m+1] = {1001,1001};
        vector <ll> bit(1005,0);
        for (int i = 1; i <= m; ++i) {
            cin>>baby[i].first>>baby[i].second;
        }
        sort(baby.begin(),baby.end());
        ll ans = 0;
        vector<pair<ll,int> > ctrl;
        for (int i = 1; i <= m; ++i) {
            ll cur = query(baby[i].second-1,bit);
            ans = max(ans,cur+1);
            ctrl.push_back({cur+1,baby[i].second});
            if(baby[i].first != baby[i+1].first) {
                while(!ctrl.empty()) {
                    update(ctrl.back().first,ctrl.back().second,bit);
                    ctrl.pop_back();
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}