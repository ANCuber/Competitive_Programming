#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

unsigned ll dp[80][80] = {0};

unsigned ll c(unsigned ll k, unsigned ll r) {
    if (dp[k][r]) return dp[k][r];
    if (r == 0 || r == k) return dp[k][r] = 1;
    return dp[k][r] = (c(k-1,r-1)+c(k-1,r));
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unsigned ll n, m;
    while(cin>>n>>m && n) {
        cout<<c(m+n-1,m)<<endl;
    }
    return 0;
}