#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, x;
vector<int> w(25,0);
vector< pii > dp((1<<20)+5,{1e9,0});

pii dfs(int s) {
    if (dp[s].first != 1e9) return dp[s];
    pii mn = {1e9,0};
    for (int i = 0; i < n; ++i) {
        if (s&(1<<i)) {
            pii cur = dfs(s-(1<<i));
            if (cur.second < w[i]) {
                cur.first++;
                cur.second = x-w[i];
            } else {
                cur.second -= w[i];
            }
            if ((cur.first == mn.first && cur.second > mn.second) || cur.first < mn.first) mn = cur;
        }
    }
    return dp[s] = mn;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>x;
    dp[0] = {0,0};
    for (int i = 0; i < n; ++i) cin>>w[i];
    cout<<dfs((1<<n)-1).first<<endl;
    return 0;
}
