#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int n, int m) {
    
}

int main() {
    ll n, m;
    vector <ll> fact(14,1);
    for (int i = 1; i <= 13; ++i) {
        fact[i] = i*fact[i-1];
    }
    while(cin>>n>>m && n && m) {
        ll mod = fact[n];
        m %= mod;
        m++;
        solve(n,m);
    }
}