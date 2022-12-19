#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int x, int fr, int to) {
    if (x == 1) {
        cout<<fr<<' '<<to<<endl;
        return;
    }
    int nx = 6-fr-to;
    dfs(x-1,fr,nx);
    cout<<fr<<' '<<to<<endl;
    dfs(x-1,nx,to);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int cnt = 1;
    for (int i = 2; i <= n; ++i) cnt = (cnt<<1|1);
    cout<<cnt<<endl;
    dfs(n,1,3);
    return 0;
}
