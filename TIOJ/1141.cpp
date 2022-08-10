#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int a[n+1] = {0};
    for (int i = 1; i <= n; ++i) cin>>a[i];
    sort(a,a+n+1);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (a[i]-a[i-1])*(a[i]-a[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
