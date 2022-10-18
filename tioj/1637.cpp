#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ll ans = 0;
    vector<ll> g(n+1);
    vector<int> rng(n+1);
    g[0] = g[n] = (1LL<<31); 
    for (int i = 1; i < n; ++i) {
        cin>>g[i];
    }
    stack<int,vector<int> > s;
    s.push(0);
    for (int i = 1; i < n; ++i) {
        while(g[i] >= g[s.top()]) {
            s.pop();
        }
        rng[i] = (i-s.top());
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n);
    for (int i = n-1; i > 0; --i) {
        while(g[i] > g[s.top()]) {
            s.pop();
        }
        //cout<<rng[i]<<' '<<(s.top()-i)<<endl;
        ans += (rng[i]*(s.top()-i)*g[i]);
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}
