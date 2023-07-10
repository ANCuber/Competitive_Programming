#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int num[5] = {4,6,8,12,20};

struct Val{
    int v, pp, p;
    bool operator<(Val b) {
        if (pp == b.pp) {
            if (p == b.p) return v < b.v;
            return p > b.p;
        }
        return pp > b.pp;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[5];
    vector<int> dice;
    dice.pb(0);
    for (int i = 0; i < 5; ++i) {
        cin>>a[i];
        for (int j = 0; j < a[i]; ++j) dice.pb(num[i]);
    }
    vector<vector<long double> > dp(55,vector<long double>(505,0.0));//, nx(55,vector<int>(505,0));
    dp[0][0] = 1.0;
    for (int i = 1; i < dice.size(); ++i) {
        for (int j = 1; j <= 500; ++j) {
            for (int k = max(0ll,j-dice[i]); k < j; ++k) {
                dp[i][j] += (dp[i-1][k]/(1.0*dice[i]));
                //nx[i][j] += nx[i-1][k];
                /*while(dp[i][j] >= 1e7) {
                    nx[i][j]++;
                    dp[i][j] -= 1e7;
                }*/
            }
        }
    }
    //vector<Val> ans;
    vector<pair<long double,int> > ans;
    for (int i = 1; i <= 500; ++i) {
        //ans.pb({i,nx[dice.size()-1][i],dp[dice.size()-1][i]});
        if (dp[dice.size()-1][i] > 0) ans.pb({dp[dice.size()-1][i],i});
    }
    sort(ans.begin(),ans.end(),greater<pair<long double,int> >());
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i].second;
    }
    cout<<endl;
    return 0;
}
