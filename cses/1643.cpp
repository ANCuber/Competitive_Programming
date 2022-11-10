#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, ans = -1e9, sum = 0; 
    cin>>n;    
    for (int i = 1; i <= n; ++i) {
        cin>>a;
        if (sum < 0) sum = a;
        else sum += a;
        ans = max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}
