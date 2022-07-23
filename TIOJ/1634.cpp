#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k; cin>>k;
    vector<int> a(k+1);
    for (int i = 0; i <= k; ++i) cin>>a[i];
    ll ans = a[0];
    for (int i = 1; i <= k; ++i) {
        if ((1LL<<i) > ans+1) {
            break;
        } else {
            ans += (1LL<<i)*a[i];
        }
    }
    cout<<ans+1<<endl;
    
    return 0;
}
