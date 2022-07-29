#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int n;
ll ans = 0, sum = 0;
vector<ll> g;
vector<int> rng;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    g.resize(n+1);
    rng.resize(n+1);
    g[0] = g[n] = (1<<31);
    for (int i = 1; i < n; ++i) cin>>g[i];
    stack <int> s;
    s.push(0);
    for (int i = 1; i < n; ++i) {
        while(!s.empty() && g[i] >= g[s.top()]) {
            s.pop();
        }
        rng[i] = i-s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n);
    for (int i = n-1; i >= 0; ++i) {
        while(!s.empty() && g[i] >= g[s.top()]) {
            s.pop();
        }
        ans += rng[i]*(s.top()-i)*g[i];
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}
