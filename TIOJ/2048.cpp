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
    int n; cin>>n;
    vector<ll> a(n+1), mxs(n+1);
    a[0] = mxs[0] = 0;
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i <= n; ++i) mxs[i] = max(a[i],mxs[i-1]+a[i]);
    
    return 0;
}
