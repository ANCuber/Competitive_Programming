#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    while(cin>>n) {
        if (!n) break;
        int ans = 1e9;
        vector <vector<int> > dis(n,vector<int>(n,1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>dis[i][j];
                if (!dis[i][j]) dis[i][j] = 1e9;
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            ans = min(ans,dis[i][i]);
        }
        if (ans >= 1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}