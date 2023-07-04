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
    int a, b; cin>>a>>b;    
    if (a > b) swap(a,b);
    int ans = 0;
    a = 2*a-2;
    b = 2*b-2;
    for (int i = 2; i < a; i += 2) {
        int cur = a*a-i*i;
        int sq = sqrt(cur);
        if (cur == sq*sq && (sq*b)%a == 0 && (i*b)%a == 0) ans++;
    }
    
    if (a == b) cout<<ans+1<<endl;
    else cout<<ans*2+2<<endl;
    
    return 0;
}
