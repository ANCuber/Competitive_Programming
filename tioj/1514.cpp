#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int MAXN = 1e6+5;
ll ans[MAXN] = {0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     
    int n;
    while(cin>>n && n >= 0) cout<<ans[n]<<endl;
    return 0;
}
