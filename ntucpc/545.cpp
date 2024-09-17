#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

inline int cal(int t, int x, int y, int a[]) {
    return a[t]*x+a[t+1]*y <= a[t+2];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int ux, uy, ans = 0; cin>>ux>>uy;
    int a[10];
    for (int i = 0; i < 9; ++i) cin>>a[i];
    for (int i = 0; i <= 1e3; ++i) {
        for (int j = 0; j <= 1e3; ++j) {
            int flg = 1;
            for (int k = 0; k < 3; ++k) if (!cal(k*3,i,j,a)) flg = 0;
            if (flg) ans = max(ans,ux*i+uy*j);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
