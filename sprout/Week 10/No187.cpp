#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
int n;

ll solve(vector <vector <int> > &graph,vector <vector <ll> > &dp,int now, int state) {
    if (dp[now][state]+1) return dp[now][state];
    ll ans = 1e12;
    for (int i = 0; i < n; ++i) {
        if (((state>>i)&1) && i != now) {
            ans = min(ans,solve(graph,dp,i,state-(1<<now))+graph[i][now]);
        }
    }
    dp[now][state] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        if (n == 1) {
            cout<<0<<endl;
            continue;
        }
        vector <vector <int> > graph(n,vector <int> (n,0));
        ll size = 1<<n;
        vector <vector <ll> > dp(n,vector <ll> (size,-1));
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int d; cin>>d;
                graph[i][j] = d;
                graph[j][i] = d;
            }
        }
        for (int i = 1; i < n; ++i) {
            dp[i][1<<i] = graph[0][i];
        }
        ll ans = 1e12;
        for (int i = 1; i < n; ++i) {
            ans = min(ans,solve(graph,dp,i,size-2)+1LL*graph[0][i]);
        }

        cout<<ans<<endl;
    }
    return 0;
}

/* 
2
3
1 2
3 
4
1 3 6
2 5
4 
*/