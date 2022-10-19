#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int arr[300005] = {0}, s[300005] = {0};
int n, m, k, ans = 0;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;    
    while(m--) {
        cin>>k;
        arr[k]++;
    }
    for (int i = 1; i <= n; ++i) for (int j = i; j <= n; j += i) s[j] += arr[i];
    for (int i = 1; i <= n; ++i) ans += (1&s[i]);
    cout<<ans<<endl;
    for (int i = 1; i <= n; ++i) if (1&s[i]) cout<<i<<endl;
    
    return 0;
}
