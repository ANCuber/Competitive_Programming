#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n; cin>>n;
    vector <vector<int> > dis(n,vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>dis[i][j];
            if (dis[i][j] == -1) dis[i][j] = 1e9;
        }
    }
    cout<<0;
    for (int i = 1; i < n; ++i) {
        int ans = -1;
        for (int k = 0; k <= i; ++k) {
            for (int l = 0; l <= i; ++l) {
                dis[k][i] = min(dis[k][i],dis[k][l]+dis[l][i]);
                dis[i][k] = min(dis[i][k],dis[i][l]+dis[l][k]);
            }
        }
    
        for (int k = 0; k <= i; ++k) {
            for (int l = 0; l <= i; ++l) {
                dis[k][l] = min(dis[k][l],dis[k][i]+dis[i][l]);
                ans = max(ans,dis[k][l]);
            }
        }

        if (ans >= 1e9) cout<<' '<<-1;
        else cout<<' '<<ans;
    }
    cout<<endl;
    return 0;
}
