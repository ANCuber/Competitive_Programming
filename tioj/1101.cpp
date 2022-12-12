#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define mid ((l+r)>>1)
#define int ll 

int solve(int l, int r, int bm, int tp, int tar) {
    if (l == r) return bm+tp;
    if (tar <= mid) return solve(l,mid,bm,bm+tp,tar);
    else return solve(mid+1,r,bm+tp,tp,tar);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m && n && m) {
        if (n == 1) {
            if (m == 1) cout<<"0/1"<<endl;
            else cout<<"1/0"<<endl;
        } else {
            cout<<solve(1,1<<(n-2),0,1,m)<<'/'<<solve(1,1<<(n-2),1,0,m)<<endl;
        }
    }
    return 0;
}
