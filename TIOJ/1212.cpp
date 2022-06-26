#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m && n && m) {
        vector<vector<int> > dis(n+1,vector<int>(n+1,1e9));
        while(m--) {
            int a, b; cin>>a>>b;
            dis[a][b] = 1;
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int minn = 1e9;
        for (int i = 1; i <= n; ++i) {
            minn = min(minn,dis[i][i]);
        }
        if (minn >= 1e9) cout<<0<<endl;
        else cout<<minn<<endl;
    }
    return 0;
}