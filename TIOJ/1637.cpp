#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

ll ans = 0;
vector<ll> g;
vector<ll> bit;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    g.resize(n+1);
    bit.resize(n+1);
    for (int i = 1; i <= n; ++i) cin>>g[i];
    return 0;
}
