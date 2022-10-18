#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int rn, cn;
    while(cin>>rn>>cn) {
        int g[rn+1][cn+1];
        int alt = -1e9;
        vector<vector<int> > pre(rn+1,vector<int>(cn+1,0));
        for (int i = 1; i <= rn; ++i) {
            for (int j = 1; j <= cn; ++j) {
                cin>>g[i][j];
                alt = max(alt,g[i][j]);
                pre[i][j] = pre[i-1][j]+g[i][j];
            }
        }
        int ans = -1e9;
        for (int i = 1; i <= rn; ++i) {
            for (int j = i; j <= rn; ++j) {
                int pm = -1e9;
                for (int k = 1; k <= cn; ++k) {
                    pm = max(0,pm)+(pre[j][k]-pre[i-1][k]);
                    ans = max(ans,pm);
                }
            }
        }
        cout<<max(alt,ans)<<endl;
    }
    return 0;
} 
