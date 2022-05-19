#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;
int minans = 25;

struct Dot{
    int x, y;
};

tuple<ll,ll,ll> coeff(int x1, int y1, int x2, int y2) {
    ll del = 1LL*x1*x2*(x1-x2);
    ll del_a = 1LL*(y1*x2-x1*y2);
    ll del_b = 1LL*(y2*x1*x1-y1*x2*x2);
    return {del,del_a,del_b};
}

int solve(vector <Dot> &p, vector <int> &dp,int cur, int counter, int rest) {
    if (!cur) return counter;
    if (dp[cur]) return dp[cur];
    int ans = rest+counter;
    for (int i = 0; i < n-1; ++i) {
        if (!(cur&(1<<i))) continue;
        for (int j = i+1; j < n; ++j) {
            if (!(cur&(1<<j))) continue;
            tuple<ll,ll,ll> i_sol = coeff(p[i].x,p[i].y,p[j].x,p[j].y);
            if (get<0>(i_sol)*get<1>(i_sol) >= 0) continue;
            int ctrl = cur;
            int num = 2;
            for (int k = 0; k < n; ++k) {
                if (!(cur&(1<<k)) || k == i || k == j) continue;
                tuple<ll,ll,ll> k_sol = coeff(p[i].x,p[i].y,p[k].x,p[k].y);
                if (get<0>(i_sol)*get<1>(k_sol) == get<1>(i_sol)*get<0>(k_sol)
                    && get<0>(i_sol)*get<2>(k_sol) == get<2>(i_sol)*get<0>(k_sol)) {
                    ctrl -= (1<<k);
                    num++;
                }
            }
            ctrl -= (1<<i);
            ctrl -= (1<<j);
            ans = min(ans,solve(p,dp,ctrl,counter+1,rest-num));
        }
    }
    dp[cur] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        if (n == 1) {
            cout<<1<<endl;
            continue;
        }
        vector <int> dp(1<<n,0);
        vector <Dot> pig(n);
        for (int i = 0; i < n; ++i) cin>>pig[i].x>>pig[i].y;
        cout<<solve(pig,dp,(1<<n)-1,0,n)<<endl;
    }
    return 0;
}

/*
2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/