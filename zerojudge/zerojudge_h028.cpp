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


}