#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n';

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l; cin>>n>>l;
    vector <int> c(n+2);
    vector <int> h(n+2);
    c[0] = 0;
    h[0] = 2e9;
    for (int i = 1; i <= n; ++i) cin>>c[i];
    for (int i = 1; i <= n; ++i) cin>>h[i];
    c[n+1] = l;
    h[n+1] = 2e9;
    stack <int> stk;
    stk.push(0);
    ll ans = 0;
    int maxh = 0;
    for (int i = 1; i <= n; ++i) {
        while(!stk.empty() && c[stk.top()] + h[stk.top()] <= c[i]) {
            ans++;
            maxh = max(maxh,h[stk.top()]);
            stk.pop();
        }
        if (c[i]-h[i] >= c[stk.top()] || c[i]+h[i] <= c[i+1]) {
            ans++;
            maxh = max(maxh,h[i]);
        } else {
            stk.push(i);
        }
    }
    while(!stk.empty() && c[stk.top()]+h[stk.top()] <= l) {
        ans++;
        maxh = max(maxh,h[stk.top()]);
        stk.pop();
    }
    cout<<ans<<endl;
    cout<<maxh<<endl;
    return 0;
}