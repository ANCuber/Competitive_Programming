#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;    
    vector<vector<int> > a(m+2,vector<int>(n+2,0));
    int ans = 1e18, str = 0, cur = 0, X, Y;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>a[i][j];
            str += a[i][j]*(i+j-2);
            a[i][j] = a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i-1) str = str+a[i-1][n]-(a[m][n]-a[i-1][n]);
        cur = str;
        for (int j = 1; j <= n; ++j) {
            if (j-1) cur = cur+a[m][j-1]-(a[m][n]-a[m][j-1]);
            //cout<<cur<<' ';
            if (cur < ans) {
                ans = cur;
                X = i, Y = j;
            }
        }
        //cout<<endl;
    }
    cout<<X<<' '<<Y<<endl;
    return 0;
}
