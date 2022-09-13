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

int solve(vector <Dot> &p, vector <int> &dp,int cur) {
    //cout<<"pass#"<<counter<<' '<<rest<<endl;
    if (!cur) return 0;
    if (dp[cur]) return dp[cur];
    if (cur - (cur&-cur) == 0) return 1;
    int ans = INT_MAX;
    int start = __lg(cur&-cur);//first dot
    for (int i = start+1; i < n; ++i) {//second dot
        if (!((cur>>i)&1)) continue;
        tuple<ll,ll,ll> s_sol = coeff(p[start].x,p[start].y,p[i].x,p[i].y);
        if (get<0>(s_sol)*get<1>(s_sol) >= 0) continue;
        int ctrl = cur;// find two dots
        ctrl -= (1<<i);
        ctrl -= (cur&-cur);
        for (int j = 0; j < n; ++j) {//others
            if (!((ctrl>>j)&1) || j == i || j == start) continue;
            tuple<ll,ll,ll> k_sol = coeff(p[start].x,p[start].y,p[j].x,p[j].y);
            if (get<0>(s_sol)*get<1>(k_sol) == get<0>(k_sol)*get<1>(s_sol)
            && get<0>(s_sol)*get<2>(k_sol) == get<0>(k_sol)*get<2>(s_sol)) {
                ctrl -= (1<<j);
            }
        }
        ans = min(ans,solve(p,dp,ctrl)+1);
    }
    ans = min(ans,solve(p,dp,cur-(cur&-cur))+1);
    dp[cur] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        vector <int> dp(1<<n,0);
        vector <Dot> pig(n);
        for (int i = 0; i < n; ++i) cin>>pig[i].x>>pig[i].y;
        if (n == 1) {
            cout<<1<<endl;
            continue;
        }
        cout<<solve(pig,dp,(1<<n)-1)<<endl;
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