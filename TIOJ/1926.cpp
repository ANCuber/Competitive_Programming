#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "lib1926.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
ll n, m;

bool check(ll x, ll y) {
    bool flag = 1;
    for (ll i = 0; i < 4; ++i) {
        if (x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= m) continue;
        if (!Oshietekudasai(x,y,x+dx[i],y+dy[i])) {
            flag = 0;
        }
    }
    return flag;
}

void solve(ll l, ll r) {
    ll mid = l+(r-l)/2;
    pll low = {0,mid};
    for (int i = 0; i < n; ++i) {
        if (!Oshietekudasai(low.first,mid,i,mid)) low = {i,mid};
    }
    if (check(low.first,low.second)) Report(low.first,low.second);
    else if (mid == 0) solve(mid+1,r);
    else if (mid == m-1) solve(l,mid);
    else if (Oshietekudasai(low.first,mid,low.first,mid+1)) solve(l,mid);
    else solve(mid+1,r);
}

int main() {
    Init(&n,&m);
    solve(0,m-1);
    return 0;
}
