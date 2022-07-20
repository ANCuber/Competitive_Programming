#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

struct Pyr{
    int c, v;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, p;
    cin>>m>>n>>p;
    vector<vector<Pyr> > py(n+1,vector<Pyr>(p+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            cin>>py[i][j].c>>py[i][j].v;
        }
    }
    vector<int> dp(m+1,-1e9);
    dp[0] = 0;//0 group
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            for (int k = 1; k <= p; ++k) {
                if (j >= py[i][k].c) {
                    dp[j] = max(dp[j],dp[j-py[i][k].c]+py[i][k].v);
                }
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
}
